/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:13:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/18 16:53:56 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_end_line(char *buffer, char **line, char *tmp_line, int bytes_read)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < bytes_read)
	{
		if (buffer[j] == '\n')
		{
			tmp_line[i] = '\0';
			*line = ft_strdup(tmp_line);
			return (j + 1);
		}
		tmp_line[i++] = buffer[j++];
	}
	tmp_line[i] = '\0';
	*line = ft_strdup(tmp_line);
	return (0);
}
void	manage_remaind(char *tmp_line, char *remaind)
{
	tmp_line = malloc(sizeof(char) * (ft_strlen(remaind) + BUFFER_SIZE + 1));
	if (!tmp_line)
		return ;
	tmp_line = "\0";
	ft_strcpy(tmp_line, remaind);
	free(remaind);
	remaind = NULL;
}

int	read_line(int fd, char *buffer, char **line, char *remaind)
{
	int		bytes_read;
	int		offset;
	char	*tmp_line;

	tmp_line = "\0";
	if (remaind)
		manage_remaind(tmp_line, remaind);
	else
		tmp_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_line)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp_line);
			return (-1);
		}
		if ((offset = find_end_line(buffer, line, tmp_line, bytes_read)) > 0)
		{
			remaind = ft_strdup(buffer + offset);
			free(tmp_line);
			return (1);
		}
	}
	free(tmp_line);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			rep;
	char 		*buffer;
	static char	*remaind;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	remaind = NULL;

	rep = read_line(fd, buffer, line, remaind);
	free(buffer);
	if (rep == 1) /*Row OK*/
		return (1);
	if (rep == 0) /*End*/
		return (0);
	if (rep == -1) /*Error*/
		return (-1);
	return (0);
}
