/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:04 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/05 13:17:44 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*ft_get_remaining_str(int fd, char *rem_str)
{
	char	*buff;
	int		byt;

	byt = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(rem_str, '\n') && byt != 0)
	{
		byt = read(fd, buff, BUFFER_SIZE);
		if (byt < 0 || !buff)
		{
			free(buff);
			free(rem_str);
			return (NULL);
		}
		buff[byt] = '\0';
		rem_str = ft_strjoin(rem_str, buff);
	}
	free(buff);
	return (rem_str);
}

char	*get_next_line(int fd)
{
	static char	*rem_str;
	char		*first_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	rem_str = ft_get_remaining_str(fd, rem_str);
	if (!rem_str)
		return (NULL);
	first_line = ft_get_first_line(rem_str);
	rem_str = ft_get_new_rem_str(rem_str);
	return (first_line);
}

// int	main(void)
// {
// 	char	*line;
// 	// int		i;
// 	int		fd1;
// 	// int		fd2;
// 	// int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	// fd2 = open("tests/test2.txt", O_RDONLY);
// 	// fd3 = open("tests/test3.txt", O_RDONLY);
// 	// i = 1;
// 	line = get_next_line(fd1);
// 	// line = get_next_line(fd1);
// 	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
// 	printf("line 1: %s", line);
// 	free(line);
// 	close(fd1);
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
// 	// while (i < 7)
// 	// {
// 	// 	line = get_next_line(fd1);
// 	// 	printf("line [%02d]: %s", i, line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd2);
// 	// 	printf("line [%02d]: %s", i, line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd3);
// 	// 	printf("line [%02d]: %s", i, line);
// 	// 	free(line);
// 	// 	i++;
// 	// }
// 	// close(fd2);
// 	// close(fd3);
// 	return (0);
// }
