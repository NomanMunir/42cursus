/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:04 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/01 21:48:49 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*left_str(int fd, char *left)
{
	char	*buff;
	int		byt;

	byt = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(left, '\n') && byt != 0)
	{
		byt = read(fd, buff, BUFFER_SIZE);
		if (byt < 0)
		{
			free(buff);
			free(left);
			return (NULL);
		}
		buff[byt] = '\0';
		left = ft_strjoin(left, buff);
	}
	free(buff);
	return (left);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left[fd] = left_str(fd, left[fd]);
	if (!left[fd])
		return (NULL);
	line = ft_get_line(left[fd]);
	left[fd] = ft_new_left_str(left[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
// 	// line = get_next_line(fd1);
// 	// printf("file 1: %s\n", line);
// 	// line = get_next_line(fd2);
// 	// printf("file 2: %s\n", line);
// 	// line = get_next_line(fd3);
// 	// printf("file 3: %s\n", line);
// 	// line = get_next_line(0);
// 	// printf("line 2: %s", line);
// 	// line = get_next_line(0);
// 	// printf("line 3: %s", line);
// 	// line = get_next_line(fd1);
// 	// printf("line 4: %s", line);
// 	// printf("line 1: %s", line);
// 	// line = get_next_line(fd1);
// 	// printf("line 2: %s", line);
// 	// line = get_next_line(fd1);
// 	// printf("line 3: %s", line);
// 	// line = get_next_line(fd1);
// 	// printf("line 4: %s", line);
// 	// free(line);
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
