/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:33:38 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/18 12:03:35 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t out;

	out = ft_strlen(dst);
	if (size <= out)
		return (ft_strlen(src) + size);
	while (*src && out < size - 1)
	{
		dst[out] = *src++;
		out++;
	}
	dst[out] = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}
