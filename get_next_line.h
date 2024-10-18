/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:14:56 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/18 16:51:33 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* DEBUG */
# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*ft_strcpy(char *dest, char *src);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#endif