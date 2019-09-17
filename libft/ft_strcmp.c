/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:48:17 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/21 08:31:33 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int size_1;
	int size_2;

	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	if (size_1 == 0 || size_2 == 0)
		return (size_1 - size_2);
	if (size_1 < size_2)
		return (size_1 - size_2);
	else if (size_2 < size_1)
		return (size_1 - size_2);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
