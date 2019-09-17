/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:37:59 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/19 15:26:02 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int num, int fd)
{
	char	ch;
	int		is_lim;

	is_lim = 0;
	if (num < 0)
	{
		write(fd, "-", 1);
		if (num == -2147483648)
		{
			num = -num - 1;
			is_lim = 1;
		}
		else
			num = -num;
	}
	if (num < 10)
		ch = is_lim ? 8 + '0' : (num % 10) + '0';
	else
	{
		ch = is_lim ? 8 + '0' : (num % 10) + '0';
		ft_putnbr_fd(num / 10, fd);
	}
	write(fd, &ch, 1);
}
