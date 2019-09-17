/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:24:05 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/20 09:37:20 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *temp_src;
	unsigned char ch;

	temp_src = (unsigned char *)s;
	ch = c;
	while (n > 0)
	{
		if (*temp_src == ch)
			return ((void *)temp_src);
		temp_src++;
		n--;
	}
	return (NULL);
}
