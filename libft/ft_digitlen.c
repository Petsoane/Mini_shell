/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:12:30 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/05 14:46:31 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_digitlen(int num)
{
	int len;

	len = 1;
	while (num != 0)
	{
		len *= 10;
		num /= 10;
	}
	return (len / 10);
}