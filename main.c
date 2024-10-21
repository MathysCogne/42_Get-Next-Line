/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:18:04 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/21 19:38:48 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* MAIN - DEBUG */
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd1;
	char	*rep1;

	if (argc == 2)
		fd1 = open(argv[1], O_RDONLY);
	if (argc == 1)
		fd1 = 0;
	if (fd1 == -1)
	{
		printf("Error opening files.\n");
		return (1);
	}
	rep1 = get_next_line(fd1);
	while (rep1)
	{
		printf("File 1: %s", rep1);
		free(rep1);
		rep1 = get_next_line(fd1);
	}
	free(rep1);
	if (fd1 != 0)
		close(fd1);
	return (0);
}
