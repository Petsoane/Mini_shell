/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:37:14 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/18 18:20:01 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

/*
** This function will be used to free an array vector and its malloc'd
** holder.
*/

void	free_vector(char **vec, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(vec[i++]);
	if (vec != NULL)
		free(vec);
	vec = NULL;
}

/*
** This will join a string together without leaking any memory.
** In hind sight this can be done in the strjoin function itself.
*/

void	clean_join(char **dst, char *src)
{
	char *tmp;

	tmp = *dst;
	*dst = ft_strjoin(tmp, src);
	free(tmp);
}
