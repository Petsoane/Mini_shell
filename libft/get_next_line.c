/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:45:04 by event             #+#    #+#             */
/*   Updated: 2019/08/26 07:30:30 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_copy(char *buf, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (ft_strlen(line) > i + 1)
		buf = ft_strcpy(buf, &(line[i + 1]));
	line[i] = '\0';
	return (1);
}

static int	get_line(const int fd, char **buf, char **line)
{
	int		r;
	char	*store;

	r = 1;
	if (buf[fd][0] != '\0')
		*line = ft_strcpy(*line, buf[fd]);
	ft_bzero(buf[fd], BUFF_SIZE);
	while (!(ft_strchr(*line, '\n')) && (r = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		store = *line;
		*line = ft_strjoin(store, buf[fd]);
		free(store);
		if (!*line)
			return (-1);
		ft_bzero(buf[fd], BUFF_SIZE);
	}
	if (r >= 0 && *line[0] != '\0')
		return (line_copy(buf[fd], *line));
	return (r);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[FD_MAX];

	if (fd < 0 || fd > FD_MAX || read(fd, buf[fd], 0) < 0 || !line)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!buf[fd])
		buf[fd] = ft_strnew(BUFF_SIZE + 1);
	return (get_line(fd, buf, line));
}
