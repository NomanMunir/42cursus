/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:01:08 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/16 12:48:29 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read_string(int fd, char *rem_string)
{
	char	*buffer;
	int		read_byt;

<<<<<<< HEAD
	read_byt = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read_byt != 0 && !ft_strchr(rem_string, '\n'))
=======
	byt = 1;
	buff = malloc(sizeof(char) * ((long)BUFFER_SIZE + 1));
	while (!ft_strchr(left, '\n') && byt != 0)
>>>>>>> 6ff35208e335b3c80fc9582f03f6ba8a7c1dbd3c
	{
		read_byt = read(fd, buffer, BUFFER_SIZE);
		if (read_byt < 0)
		{
			free(buffer);
			free(rem_string);
			return (NULL);
		}
		buffer[read_byt] = '\0';
		rem_string = ft_strjoin(rem_string, buffer);
	}
	free(buffer);
	return (rem_string);
}

char	*get_next_line(int fd)
{
	static char	*rem_string[FD_MAX];
	char		*res;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rem_string[fd] = get_read_string(fd, rem_string[fd]);
	if (!rem_string[fd])
		return (NULL);
	res = get_first_line(rem_string[fd]);
	rem_string[fd] = get_new_rem_str(rem_string[fd]);
	return (res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int		fd1;
// 	char	*line;

// 	fd1 = open("tests/test.txt", O_RDWR | O_APPEND);
// 	write(fd1, "aab\0bb\n",7);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	close(fd1);
// 	return (0);
// }
