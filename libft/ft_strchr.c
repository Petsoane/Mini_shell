/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:41:24 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/27 08:55:51 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) + 1;
	while (i > 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		i--;
	}
	return (NULL);
}
