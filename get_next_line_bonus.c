/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:24:24 by stuna             #+#    #+#             */
/*   Updated: 2023/12/13 11:53:25 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*update_line(char **line, char *buffer)
{
	char	*temp;

	temp = mt_strjoin(*line, buffer);
	free(*line);
	if (!temp)
		return (NULL);
	*line = mt_strjoin("", temp);
	free(temp);
	if (!*line)
		return (NULL);
	return (*line);
}

char	*resize_str(char *str)
{
	char	*tmp_str;

	tmp_str = malloc(ft_strlen(str) + 1);
	if (!tmp_str)
	{
		free(str);
		return (NULL);
	}
	mth_strjoin(tmp_str, str, "");
	free(str);
	return (tmp_str);
}

static void	update_buff(char *buffer, int pos)
{
	int	i;

	i = 0;
	if (pos != -1)
	{
		while (buffer[pos + i] != '\0')
		{
			buffer[i] = buffer[pos + i];
			i++;
		}
	}
	buffer[i] = 0;
}

char	*next_line_parse(int buff_size, int pos, char *buffer, char **line)
{
	if (pos != -1)
	{
		update_buff(buffer, isnewline(buffer) + 1);
		*(*line + pos + 1) = 0;
	}
	else
		buffer[0] = 0;
	if (buff_size == -1)
	{
		free(*line);
		return (NULL);
	}
	if (buff_size == 0 && ft_strlen(*line) == 0)
	{
		free(*line);
		return (NULL);
	}
	return (resize_str(*line));
}

char	*get_next_line(int fd)
{
	static char	buff[OPEN_FILES_MAX][BUFFER_SIZE + 1];
	char		*buffer;
	char		*line;
	int			buff_size;
	int			pos;

	if (fd >= OPEN_FILES_MAX)
		return (NULL);
	buffer = (char *)buff[fd];
	if (!init(&line, fd, buffer, &buff_size))
		return (NULL);
	pos = isnewline(line);
	while (pos == -1)
	{
		buff_size = read(fd, buffer, BUFFER_SIZE);
		if (buff_size <= 0)
			break ;
		buffer[buff_size] = '\0';
		if (!update_line(&line, buffer))
			return (NULL);
		pos = isnewline(line);
	}
	return (next_line_parse(buff_size, pos, buffer, &line));
}
