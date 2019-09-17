/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 09:17:32 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/05 15:03:24 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int size1;
	int size2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	size1 = 0;
	size2 = 0;
	while (s1[size1])
		size1++;
	while (s2[size2])
		size2++;
	if (size1 < size2 || size1 > size2)
		return (0);
	while (*s1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}
