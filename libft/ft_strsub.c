/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:01:22 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 12:02:51 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*out;
	int		i;

	i = 0;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	s1 += start;
	while (*s1 && len--)
		out[i++] = *s1++;
	out[i] = '\0';
	return (out);
}
