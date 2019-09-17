/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:16:51 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/18 11:16:31 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *temp_dst;
	unsigned char *temp_src;

	temp_dst = (unsigned char *)dst;
	if (!(dst) && !(src))
		return (NULL);
	temp_src = (unsigned char *)ft_memalloc(n);
	ft_memcpy(temp_src, src, n);
	while (n > 0)
	{
		*temp_dst++ = *temp_src++;
		n--;
	}
	return (dst);
}
