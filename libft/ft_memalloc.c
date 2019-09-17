/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 08:54:40 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/27 07:34:15 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*r_mem;

	r_mem = (unsigned char *)malloc(size);
	if (!r_mem)
		return (NULL);
	ft_bzero((void *)r_mem, size);
	return ((void *)r_mem);
}
