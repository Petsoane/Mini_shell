/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 07:08:54 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/18 18:19:38 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

/*
** This function gets the position an environment variable.
*/

int		env_var_pos(char **env, char *var_name)
{
	int		pos;

	pos = 0;
	while (env[pos] != NULL)
	{
		if (ft_strncmp(env[pos], var_name, ft_strlen(var_name)) == 0)
			return (pos);
		pos++;
	}
	return (-1);
}

/*
** This function gets the environment variable value.
*/

char	*env_var_value(char **env, char *var_name)
{
	char	*out;
	int		ret;

	ret = env_var_pos(env, var_name);
	out = ret != -1 ? ft_strdup(env[ret] + ft_strlen(var_name) + 1) : NULL;
	return (out);
}

/*
** This function prints the environment variables on the screen
*/

void	print_env(char **env)
{
	while (*env != NULL)
	{
		ft_putendl(*env++);
	}
}

/*
** This is the builtin function for 'env'.
** it is still not complete.
*/

void	environment(char **env, char **av)
{
	int		ac;

	ac = 0;
	while (av[ac] != NULL)
		ac++;
	if (ac == 0)
		print_env(env);
}

int		valid_env_var(char *new_var)
{
	int		valid_form;

	valid_form = -1;
	while (*new_var)
	{
		if (*new_var == ' ')
			return (-1);
		if (*new_var == '=')
			valid_form = 1;
		new_var++;
	}
	return (valid_form);
}
