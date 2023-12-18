/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:38:10 by stuna             #+#    #+#             */
/*   Updated: 2023/12/13 11:53:56 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*init(char **line, int fd, char *buffer, int *buff_size)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	*buff_size = 0;
	*line = mt_strjoin("", buffer);
	if (!line)
		return (NULL);
	return (*line);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	mth_strjoin(char *str, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*mt_strjoin(char *s1, char *s2)
{
	char	*str;
	int		str_1_len;
	int		str_2_len;

	if (!s1)
		str_1_len = 0;
	else
		str_1_len = ft_strlen(s1);
	if (!s2)
		str_2_len = 0;
	else
		str_2_len = ft_strlen(s2);
	str = malloc(str_1_len + str_2_len + 1);
	if (!str)
		return (0);
	mth_strjoin(str, s1, s2);
	return (str);
}

int	isnewline(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
