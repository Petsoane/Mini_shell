/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:56:13 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/19 15:35:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	sigmain(int i)
{
	(void)i;
	ft_putstr("int the external:");
	ft_putstr("\n");
}

void	run_bin(char **argv, char **env)
{
	char	*bin_path;
	int		pid;

	bin_path = get_bin_path(env_var_value(env, "PATH"), *argv);
	if (bin_path != NULL || *argv[0] == '/')
	{
		signal(SIGINT, sigmain);
		if (bin_path == NULL)
			bin_path = *argv;
		pid = fork();
		if (pid == 0)
			if (execve(bin_path, argv, env) == -1)
			{
				print_form("%s: command does not exist\n", *argv);
				exit(0);
			}
		if (ft_strcmp(bin_path, *argv) != 0)
			free(bin_path);
		wait(NULL);
		return ;
	}
	else
		print_form("lsh: command does not exist : %s\n", *argv);
}

char	*get_bin_path(char *path_var, char *bin_name)
{
	char	*out;
	char	**bin_paths;
	int		i;

	if (!path_var)
		return (NULL);
	bin_paths = ft_strsplit(path_var, ':');
	i = 0;
	while (bin_paths[i] != NULL)
	{
		out = ft_strdup(bin_paths[i]);
		clean_join(&out, "/");
		clean_join(&out, bin_name);
		if (access(out, F_OK) == 0)
		{
			free_vector(bin_paths, env_var_count(bin_paths));
			free(path_var);
			return (out);
		}
		free(out);
		i++;
	}
	free(path_var);
	free_vector(bin_paths, env_var_count(bin_paths));
	return (NULL);
}
