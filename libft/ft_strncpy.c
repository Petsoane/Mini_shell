/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:15:49 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/27 08:01:41 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t i;

	i = 0;
	while (*src && len != 0)
	{
		dst[i++] = *src++;
		len--;
	}
	if (ft_strlen(src) < (int)len)
		while (len > 0)
		{
			dst[i++] = '\0';
			len--;
		}
	return (dst);
}
