/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:14:56 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/20 10:50:48 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* DEBUG */
# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_read(int fd, char **buffer);
int		find_end_line(char **line, char *buffer);

int		extract_line(int fd, char **line, char **remaind);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

#endif