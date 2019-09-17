/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_wordlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:02:09 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 16:07:16 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_wordlen(const char *s, char c)
{
	int len;
	int tmp;

	tmp = 0;
	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			tmp++;
			s++;
		}
		if (tmp > len)
			len = tmp;
	}
	return (len);
}
