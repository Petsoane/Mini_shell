/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:59:49 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 18:25:47 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len <= 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < len - 1)
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
