/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:04 by nmunir            #+#    #+#             */
/*   Updated: 2023/07/23 19:51:55 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		bytes;
	char	*buff;

	bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes = read(fd, buff, BUFFER_SIZE);
	buff[bytes] = '\0';
	printf("%s %d", buff, bytes);
	return (line);
}


int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	line = get_next_line(fd1);
	// printf("line 1: %s", line);
	// line = get_next_line(fd1);
	// printf("line 2: %s", line);
	// line = get_next_line(fd1);
	// printf("line 3: %s", line);
	// line = get_next_line(fd1);
	// printf("line 4: %s", line);
	// free(line);
	// while (i < 7)
	// {
	// 	line = get_next_line(fd1);
	// 	printf("line [%02d]: %s", i, line);
	// 	free(line);
	// 	line = get_next_line(fd2);
	// 	printf("line [%02d]: %s", i, line);
	// 	free(line);
	// 	line = get_next_line(fd3);
	// 	printf("line [%02d]: %s", i, line);
	// 	free(line);
	// 	i++;
	// }
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
