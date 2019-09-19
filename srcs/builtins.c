/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:31:40 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/18 18:56:41 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int		parse_command(char **av, char **env)
{
	static char			*commands[COMMANDS];
	static t_functions	exec[FUNCTIONS];
	int					i;

	i = 0;
	if (env_var_pos(env, BUILTS) == -1)
	{
		prep_commands(commands);
		builtin_functions(exec);
		add_var_builtins(env, commands);
	}
	while (i < FUNCTIONS)
	{
		if (ft_strcmp(av[0], commands[i]) == 0)
			break ;
		i++;
	}
	if (commands[i] == NULL)
		return (-1);
	else
		exec[i](env, av + 1);
	return (0);
}

void	which(char **env, char **av)
{
	int		ac;
	int		i;
	char	*path;
	char	*var_value;
	char	**split;

	ac = env_var_count(av);
	if (ac != 0)
	{
		i = 0;
		var_value = env_var_value(env, BUILTS);
		split = ft_strsplit(var_value, ':');
		while (i != ac)
			if (is_builtins(av[i], split) == 1)
				print_form("%s: shell builtin command\n");
			else if ((path = get_bin_path(env_var_value(env, "PATH"),
							av[i++])) != NULL)
			{
				ft_putendl(path);
				free(path);
			}
		free_vector(split, env_var_count(split));
		free(var_value);
	}
}

void	cd(char **env, char **av)
{
	int		i;
	char	*path;
	char	*pwd;
	char	cwd[255];

	i = 0;
	path = NULL;
	while (av[i] != NULL)
		i++;
	if (i == 0 || ft_strcmp(av[0], "~") == 0 || ft_strcmp(av[0], "-") == 0)
	{
		if (i == 0 || ft_strcmp(av[0], "~") == 0)
			path = env_var_value(env, "HOME");
		else if (ft_strcmp(av[0], "-") == 0)
			path = env_var_value(env, "OLDPWD");
		(chdir(path) == -1) ? ft_putendl(PATHERR) : 0;
		free(path);
	}
	else if (chdir(av[0]) == -1)
		ft_putendl("pwd : no such file or directory");
	pwd = env_var_value(env, "PWD");
	set_env_var(env, "OLDPWD", pwd);
	getcwd(cwd, sizeof(cwd));
	set_env_var(env, "PWD", cwd);
	free(pwd);
}

void	echo(char **env, char **av)
{
	char	*tmp;

	tmp = ft_strdup(env[0]);
	free(tmp);
	while (*av != NULL)
	{
		tmp = *av;
		if (*tmp == '"')
			tmp++;
		ft_putstr(tmp);
		ft_putstr(" ");
		av++;
	}
	ft_putendl("");
}

void	pwd(char **env, char **av)
{
	char cwd[255];
	char *tmp;

	tmp = ft_strdup(env[0] != NULL ? env[0] : " ");
	free(tmp);
	tmp = ft_strdup(av[0] != NULL ? av[0] : " ");
	free(tmp);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		ft_putendl("Error printing the directory");
	ft_putendl(cwd);
}
