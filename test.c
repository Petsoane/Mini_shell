/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:27:18 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/11 13:12:12 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
# include <signal.h>

typedef void (*functions)();
void	echo(char **av, char **env);
void	cd(char **av, char **env);
void	pwd(char **av, char **env);
char	**get_input(char **env);
int		env_var_position(char **env, char *variable_name);
char	*env_var_value(char **env, char *variable_name);
char	**prep_env_vec(char **sys_env, int ac);
void	print_env(char **av, char **env);
void	environment(char **av, char **env);
int		valid_env_var(char *new_var);
void	set_env(char **env, char *new_var);
void	unset_env_var(char **av, char **env);
void	set_env_var(char **env, char *var_name, char *var_val);
char	*which(char *command, char *path_var);

// Create a function to free all the NULL terminated vectors.
// Also create a set of functions to handle the errors.
// add The variable interpolation to the shell functions get_input.

void	handle_sigint(int sig)
{
	ft_putstr("\b \b\b \n$>");
	signal(SIGINT, handle_sigint);
}

void	handle_childkill(int i)
{
	ft_putstr("\n");
}

int main(int arr_c, char **av, char **sys_env)
{
	static int		ac;
    char **input_split;
	char *commands[6];
	functions exec[5];
	char **env;

	signal(SIGINT, handle_childkill);

	exec[0] = &echo;
	exec[1] = &cd;;
	exec[2] = &pwd;
	exec[3] = &environment;
	exec[4] = &unset_env_var;
	commands[0] = "echo";
	commands[1] = "cd";
	commands[2] = "pwd";
	commands[3] = "env";
	commands[4] = "unset";
	commands[5] = NULL;


	while (sys_env[ac] != NULL)
		ac++;	// This can be renamed envc
	env = prep_env_vec(sys_env, ac);	
    while (1)
    {
		input_split = get_input(env); 
		if (*input_split == NULL)
			continue;
		if (ft_strcmp(*input_split, "exit") == 0)
			break;
		// This part checks if the input is an environment variable.
		if (valid_env_var(*input_split) == 1)
		{
			set_env(env, *input_split);
			input_split++;
		}
		// Tf there are still commands in the input process them.
		if (*input_split != NULL){
			int i = 0;
			while (i < 5){
				if (commands[i] != NULL && ft_strcmp(input_split[0], commands[i]) == 0)	
					break;
				i++;
			}
			if (commands[i] == NULL)
			{
				char *bin_path;
				if ((bin_path = which(input_split[0], env_var_value(env, "PATH"))) != NULL)
				{
					int pid = fork();

					if (pid == 0)
					{
						/* signal(SIGINT, handle_childkill); */
						execve(bin_path, input_split, env);
						return (0);
					}

					wait(NULL);
				}
				else
					ft_putendl("The command does not exist");
			}
			else
			{
				exec[i](input_split + 1, env);
			}
			while (*input_split != NULL)
			{
				free(*input_split++);
			}
		}
	}
	int i = 0;
	print_env(NULL, env);
	while (env[i] != NULL)
	{
		free(env[i++]);
	}
	return (0);
}

char	*which(char *command, char *path_var)
{
	char **paths;
	char *out;
	char *tmp;

	out = NULL;
	paths = ft_strsplit(path_var, ':');
	while (*paths != NULL)
	{
		out = ft_strdup(*paths);
		tmp = out;
		out = ft_strjoin(out, "/");
		free(tmp);
		// add the command name
		tmp = out;
		out = ft_strjoin(out, command);
		free(tmp);
		if (access(out, F_OK) == 0)
			return (out);
		free(out);
		paths++;
	}
	return (NULL);
}

void	unset_env_var(char **av, char **env)
{
	int prev;
	int pos;
	char *tmp;

	while (*av != NULL)
	{
		pos = env_var_position(env, *av);
		if (pos != -1)
		{
			tmp = env[pos];
			prev = pos;
			pos++;
			while (env[pos] != NULL)
			{
				env[prev] = env[pos];
				prev = pos;
				pos++;
			}
			env[prev] = env[pos];
			free(tmp);
		}
		av++;
	}
}

// this function serves as the env function.
// It is not complete, i still need to add the process creation functionality.
void	environment(char **av, char **env)
{
	int ac;

	ac = 0;
	while (av[ac] != NULL)
	{
		ac++;
	}
	if (ac == 0)
		print_env(NULL, env);
}

// this will print the environment variables.
void	print_env(char **av, char **env)
{
	while (*env != NULL)
	{
		ft_putendl(*env++);
	}
}

int		env_count(char **env)
{
	int ac;

	ac = 0;
	while (env[ac] != NULL)
	{
		ac++;
	}
	return (ac);
}

int		valid_env_var(char *new_var)
{
	int valid;

	valid = 0;
	while (*new_var)
	{
		if (*new_var == ' ')
			return (-1);
		if (*new_var == '=')
			valid = 1;
		new_var++;
	}
	if (valid == 1)
		return (1);
	else return (-1);
}

void	set_env(char **env, char *new_var)
{
	char *var_name;
	char *var_val;
	int i;

	i = 0;
	while (new_var[i] != '=')
	{
		i++;
	}
	var_name = ft_strndup(new_var, i);
	ft_putendl(var_name);
	var_val = ft_strdup(new_var + (i + 1));
	ft_putendl(var_val);
	set_env_var(env, var_name, var_val);
	free(var_name);
	free(var_val);
}
// this function sets the environment variable.
// Later it will also add a new environment variable.
// This function is totaly different setenv, and should be changed into change environment variable.
void	set_env_var(char **env, char *var_name, char *new_val)
{
	int pos;
	char *new_env_var;
	char *tmp;

	// start a new environment variable.
	new_env_var = ft_strdup(var_name);
	tmp = new_env_var;
	new_env_var = ft_strjoin(new_env_var, "=");
	free(tmp);

	// join the new value to the string.
	tmp = new_env_var;
	new_env_var = ft_strjoin(new_env_var, new_val);
	free(tmp);

	pos = env_var_position(env,var_name);
	if (pos != -1)
	{
		char *tmp = env[pos];
		env[pos] = new_env_var;
		free(tmp);
	}
	else
	{
	int env_c = env_count(env);
	env[env_c] = new_env_var;
	env[env_c + 1] = NULL;
	}
	// this is where the adding a variable will be placed.
}

// This function is used to create a copy of the environment vector
// giving me the ability to create, edit and remove environment variables.
// the size of the env vec should be a fixed size on and non increasing.
char	**prep_env_vec(char **sys_env, int ac)
{
	char **env;
	int	i;

	env = (char **)malloc(sizeof(char *) * (ac * 2));
	i = 0;
	while (sys_env[i] != NULL)
	{
		env[i] = ft_strdup(sys_env[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

// This function is used to get the value of a specific environment variable.
char	*env_var_value(char **env, char *variable_name)
{
	char *out;
	int pos;

	out = NULL;
	pos = env_var_position(env, variable_name);
	if (pos != -1)
		out = ft_strdup(env[pos] + ft_strlen(variable_name) + 1);
	return (out);
}

// This will searh for the variable in the set of environment variables.
int		env_var_position(char **env, char *variable_name)
{
	int pos;

	pos = 0;
	while (env[pos] != NULL){
		if (ft_strncmp(env[pos], variable_name, ft_strlen(variable_name)) == 0){
			return (pos);
		}
		pos++;
	}
	return (-1);
}

// This is where all the cool input tricks will processed.
char	**get_input(char **env)
{
	char **input_split;
	char *input;
	int ret;

	signal(SIGINT, handle_sigint);

	ft_putstr("$>");
	ret = get_next_line(1, &input);
	input_split = ft_strsplit(input, ' ');
	// check for any variable that are in the input
	int i = 0;
	char *var_value;
	char *tmp;
	while (input_split[i] != NULL)
	{
		if (input_split[i][0] == '$' && input_split[i][1] != ' ')
		{
			tmp = input_split[i];
			var_value = env_var_value(env, tmp + 1);
			tmp = input_split[i];
			input_split[i] = var_value != NULL ? var_value : ft_strdup("");
			free(tmp);
		}
		i++;
	}
	free(input);
	return (input_split);
}

void	pwd(char **av, char **env)
{
	int i = 0;
	static char cwd[255];

	while (av[i] != NULL)
	{
		i++;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_putendl("pwd error");
	}
	else
		ft_putendl(cwd);
}

/* In order for 'cd' and other functionalities to work properly
 * I need to handle and process the environment variables */
void	cd(char **av, char **env)
{
	int ret;
	int i = 0;
	char *path;


	// this can be moved to another fucntion of its own.
	while (av[i] != NULL)
	{
		i++;
	}
	// I need to handle the HOME environment variable.
	// After which i can start processing the other corner cases of cd.
	if (i == 0 || ft_strcmp(av[0], "~") == 0)
		path = env_var_value(env, "HOME");
	else
		path = av[0];
	if ((ret = chdir(path)) == -1)
	{
		ft_putendl("Error changing directory");
	}
	char *pwd = env_var_value(env, "PWD");
	char cwd[255];
	set_env_var(env, "OLDPWD", pwd);
	getcwd(cwd, sizeof(cwd));
	set_env_var(env, "PWD", cwd);
	free(pwd);
	// either duplicate the path or dont free it.
	/* pwd(av+i, env); */
}

// I need to handle the environment variables before i can 
// make echo work properly.
void	echo(char **av, char **env)
{
	while (*av != NULL)
	{
		ft_putstr(*av);
		ft_putstr(" ");
		av++;
	}
	ft_putendl("");
}
