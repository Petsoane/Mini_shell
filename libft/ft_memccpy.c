/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 08:36:56 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/21 08:30:20 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *temp_dst;
	unsigned char *temp_src;
	unsigned char ch;

	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	ch = c;
	while (n > 0)
	{
		*temp_dst = *temp_src;
		temp_src++;
		n--;
		if (*temp_dst == ch)
		{
			temp_dst++;
			return ((void *)temp_dst);
		}
		temp_dst++;
	}
	return (NULL);
}
