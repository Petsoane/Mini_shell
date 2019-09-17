/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:29:02 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/09/02 12:06:56 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define LINE_BUFF 100
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define FD_MAX 1024
# define IS_BUFF_EMPTY file.buff[0] == '\0'

typedef struct		s_buff
{
	char			*buff;
	char			*start;
	char			*tmp;
}					t_buff;

int					get_next_line(const int fd, char **line);
#endif
