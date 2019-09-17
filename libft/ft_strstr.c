/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:19:04 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/03 09:23:44 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		i;
	int		size_n;

	i = 0;
	size_n = ft_strlen(n);
	if (size_n == 0)
		return ((char *)h);
	while (*h)
	{
		i = 0;
		while (*(h + i) == n[i])
		{
			if (n[i + 1] == '\0')
				return ((char *)h);
			i++;
		}
		h++;
	}
	return (NULL);
}
