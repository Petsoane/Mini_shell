/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:40:01 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/05 14:42:58 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ifalloc(int isneg, int size)
{
	char	*out;

	if (isneg == 1)
		return (out = (char*)malloc(sizeof(char) * size + 3));
	return (out = (char *)malloc(sizeof(char) * size + 2));
}
