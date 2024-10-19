/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:18:04 by mcogne--          #+#    #+#             */
/*   Updated: 2024/10/19 17:54:20 by mcogne--         ###   ########.fr       */
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
	if (argc == 3)
	{
		printf("Lecture avec arg\n");
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
	}
	// else if (argc == 1)
	// {
	// 	printf("Lecture avec entree standard\n");
	// 	// ENTREE STANDARD //
	// }
	else
	{
		(void)argv;
		fd1 = open("./files/file_1.txt", O_RDONLY);
		fd2 = open("./files/file_2.txt", O_RDONLY);
	}
	
	if (fd1 == -1 || fd2 == -1)
	{
		printf("Error opening files.\n");
		return (1);
	}
	
	
	
	// if ((rep2 = get_next_line(fd2, &line)) > 0)
	// {
	// 	printf("File 2: %s\n", line);
	// 	free(line);
	// }
	while ((rep1 = get_next_line(fd1, &line)) > 0)
	{
		printf("File 1: %s\n", line);
		free(line);
	}
	// if ((rep2 = get_next_line(fd2, &line)) > 0)
	// {
	// 	printf("File 2: %s\n", line);
	// 	free(line);
	// }
	


	if (rep1 == -1 || rep2 == -1)
		printf("Error read files\n");
	
	if (rep1 == 0)
		printf("\n- End file 1 -\n");
	if (rep2 == 0)
		printf("- End file 2 -\n");
	close(fd1);
	close(fd2);

	return (0);
}
