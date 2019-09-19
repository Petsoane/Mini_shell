/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:39:20 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/19 15:34:33 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int		is_builtins(char *command, char **split)
{
	while (*split != NULL)
	{
		if (ft_strcmp(*split, command) == 0)
			return (1);
		split++;
	}
	return (0);
}

void	prep_commands(char **av)
{
	av[0] = "echo";
	av[1] = "cd";
	av[2] = "pwd";
	av[3] = "env";
	av[4] = "unset";
	av[5] = "which";
	av[6] = "set";
	av[7] = NULL;
}

void	builtin_functions(t_functions *exec)
{
	exec[0] = &echo;
	exec[1] = &cd;
	exec[2] = &pwd;
	exec[3] = &environment;
	exec[4] = &unset_env_var;
	exec[5] = &which;
	exec[6] = &set;
}

void	add_var_builtins(char **env, char **commands)
{
	int		i;
	char	*path;
	char	*tmp;

	path = ft_strdup(commands[0]);
	i = 1;
	while (commands[i] != NULL)
	{
		tmp = path;
		path = ft_strjoin(tmp, ":");
		free(tmp);
		tmp = path;
		path = ft_strjoin(tmp, commands[i]);
		free(tmp);
		i++;
	}
	set_env_var(env, BUILTS, path);
	free(path);
}

void	set(char **env, char **av)
{
	int i;

	i = 0;
	while (av[i] != NULL && valid_env_var(av[i]) == 1)
	{
		set_env(env, av[i]);
		i++;
	}
}
