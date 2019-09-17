/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:55:22 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/27 07:38:33 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*out;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * size + 1);
	if (!out)
		return (NULL);
	while (*s)
		out[i++] = *s++;
	out[i] = '\0';
	return (out);
}
