/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:18:04 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/18 15:00:31 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* MAIN - DEBUG */
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char	*line;
	int		fd1, fd2;
	int		rep1, rep2;
	rep2 = 0;
	fd1 = open("./files/file_1.txt", O_RDONLY);
	fd2 = open("./files/file_2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		printf("Error opening files.\n");
		return (1);
	}

	while ((rep1 = get_next_line(fd1, &line)) > 0)
	{
		printf("Files 1: %s\n", line);
		free(line);
		// if ((rep2 = get_next_line(fd2, &line)) > 0)
		// {
		// 	printf("Files 2: %s\n", line);
		// 	free(line);
		// }
	}
	if (rep1 == -1 || rep2 == -1)
	{
		printf("Error read files\n");
		return (1);
	}
	
	if (rep1 == 0)
		printf("\n- End file 1 -\n");
	// if (rep2 == 0)
	// 	printf("- End file 2 -\n");
	(void)rep2;
	close(fd1);
	close(fd2);

	// ADD TEST ENTREE STANDARD //
	return (0);
}
