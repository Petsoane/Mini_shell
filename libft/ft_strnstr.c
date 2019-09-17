/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:19:21 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/21 08:00:31 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t size)
{
	int		i;
	int		size_n;

	i = 0;
	size_n = ft_strlen(n);
	if (size_n == 0)
		return ((char *)h);
	while (*h && size)
	{
		i = 0;
		while (*(h + i) == n[i] && size)
		{
			if (n[i + 1] == '\0')
			{
				return ((char *)h);
			}
			i++;
			size--;
		}
		h++;
		size--;
	}
	return (NULL);
}
