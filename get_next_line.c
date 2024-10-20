/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:13:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/20 11:54:49 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char **buffer)
{
	int	read_s;
	int	i;

	*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		return (-1);
	i = 0;
	while (i < BUFFER_SIZE + 1)
		(*buffer)[i++] = 0;
	read_s = read(fd, *buffer, BUFFER_SIZE);
	if (read_s < 0)
	{
		free(*buffer);
		return (-1);
	}
	(*buffer)[read_s] = '\0';
	return (read_s);
}

int	find_end_line(char **line, char *buffer)
{
	int		i;
	char	*new_line;
	char	*tmp_substr;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp_substr = ft_substr(buffer, 0, i);
	new_line = ft_strjoin(*line, tmp_substr);
	free(*line);
	free(tmp_substr);
	*line = new_line;
	if (buffer[i] == '\n')
		return (i + 1);
	return (0);
}

int	manage_remainder(char **remaind, char **line)
{
	int		pos;
	char	*new_remaind;

	if (*remaind && **remaind != '\0')
	{
		pos = find_end_line(line, *remaind);
		if (pos > 0)
		{
			new_remaind = ft_strdup(*remaind + pos);
			free(*remaind);
			*remaind = new_remaind;
			return (1);
		}
		free(*remaind);
		*remaind = NULL;
	}
	return (0);
}

int	assemble_line(int fd, char **line, char **remaind)
{
	char	*tmp_line;
	int		read_s;

	*line = ft_strdup("");
	tmp_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_line)
		return (-1);
	tmp_line[0] = '\0';
	if (manage_remainder(remaind, line))
	{
		free(tmp_line);
		return (1);
	}
	read_s = extract_line(fd, line, remaind);
	free(tmp_line);
	return (read_s);
}

int	get_next_line(int fd, char **line)
{
	static char	*remaind;
	int			rep;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	rep = assemble_line(fd, line, &remaind);
	if (rep == -1 || rep == 0)
	{
		free(remaind);
		remaind = NULL;
		return (rep);
	}
	return (rep);
}
