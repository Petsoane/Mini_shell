/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:14:07 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/20 09:30:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	run_command(char **env, char **input_split, int i)
{
	if (parse_command(input_split + i, env) == -1)
		run_bin(input_split + i, env);
	while (input_split[i] != NULL)
		free(input_split[i++]);
}

int		start(char **env)
{
	int		i;
	char	**input_split;

	i = 0;
	input_split = get_input(env);
	if (ft_strcmp(*input_split, "exit") == 0)
	{
		free_vector(input_split, env_var_count(input_split));
		return (-1);
	}
	while (input_split[i] != NULL && valid_env_var(input_split[i]) == 1)
	{
		set_env(env, input_split[i]);
		free(input_split[i++]);
	}
	if (input_split[i] == NULL)
		free(input_split);
	else
	{
		run_command(env, input_split, i);
		free(input_split);
	}
	return (0);
}

int		main(int ac, char **av, char **sys_env)
{
	char	**env;
	char	*line;
	pid_t	pid;

	(void)ac;
//	(void)av;
	line = NULL;
	env = prep_env_vec(sys_env);
	pid = fork();
	if (pid == 0)
	{
		execve("./header.sh", av, env);
		exit(0);
	}
	wait(NULL);
	while (1)
		if (start(env) == -1)
			break ;
	free_vector(env, env_var_count(sys_env) * 2);
	return (0);
}

char	**prep_env_vec(char **sys_vec)
{
	char	**env;
	int		i;

	i = env_var_count(sys_vec);
	env = (char **)malloc(sizeof(char *) * (i * 2));
	i = 0;
	while (sys_vec[i] != NULL)
	{
		env[i] = ft_strdup(sys_vec[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}
