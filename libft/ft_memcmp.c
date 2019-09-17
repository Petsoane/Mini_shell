/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:38:38 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 14:04:18 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	if (n <= 0)
		return (0);
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*temp_s1 != *temp_s2)
			return ((*temp_s1 - *temp_s2));
		temp_s1++;
		temp_s2++;
		n--;
	}
	return (0);
}
