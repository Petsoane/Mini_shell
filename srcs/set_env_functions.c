/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:14 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/18 18:20:07 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

/*
** This fucntion will change environment variable or add a new one
*/

void	set_env_var(char **env, char *var_name, char *val)
{
	int		pos;
	char	*new_env_var;
	char	*tmp;

	new_env_var = ft_strdup(var_name);
	clean_join(&new_env_var, "=");
	clean_join(&new_env_var, val);
	pos = env_var_pos(env, var_name);
	if (pos != -1)
	{
		tmp = env[pos];
		env[pos] = new_env_var;
		free(tmp);
	}
	else
	{
		pos = env_var_count(env);
		tmp = env[pos];
		env[pos] = new_env_var;
		env[pos + 1] = NULL;
		free(tmp);
	}
}

void	set_env(char **env, char *new_var)
{
	int		i;
	char	*var_name;
	char	*var_val;

	i = 0;
	while (new_var[i] != '=')
		i++;
	var_name = ft_strndup(new_var, i);
	var_val = ft_strdup(new_var + (i + 1));
	set_env_var(env, var_name, var_val);
	free(var_name);
	free(var_val);
}

void	unset_env_var(char **env, char **av)
{
	int		pos;
	int		prev;
	char	*tmp;

	while (*av != NULL)
	{
		pos = env_var_pos(env, *av);
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

/*
** This function count the number of varibles in the environment.
*/

int		env_var_count(char **env)
{
	int		ac;

	ac = 0;
	while (env[ac] != NULL)
		ac++;
	return (ac);
}
