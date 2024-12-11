/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:08:00 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/11 20:22:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **stash)
{
	char	*line;
	char	*newline_pos;
	char	*tmp;
	size_t	len;

	len = 0;
	if (!*stash || !**stash)
		return (free(*stash), *stash = NULL, NULL);

	newline_pos = ft_strchr(*stash, '\n');
	if (newline_pos)
		len = newline_pos - *stash + 1;
	else
		len = ft_strlen(*stash);

	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
		line[len] = (*stash)[len];

	if (newline_pos)
		tmp = ft_strdup(newline_pos + 1);
	else
		tmp = NULL;
	free(*stash);
	*stash = tmp;

	return (line);
}

char	*get_next_line(int fd)
{
	static char *stash = NULL;
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);

	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (extract_line(&stash));
}