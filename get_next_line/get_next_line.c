/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:01:08 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/12 18:41:08 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_string(int fd, char *rem_string)
{
	char	*buffer;
	int		read_byt;

<<<<<<< HEAD
	read_byt = 1;
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
=======
	byt = 1;
	buff = (char *)malloc((long)(BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
>>>>>>> 6ff35208e335b3c80fc9582f03f6ba8a7c1dbd3c
		return (NULL);
	while (read_byt != 0 && !ft_strchr(rem_string, '\n'))
	{
		read_byt = read(fd, buffer, BUFFER_SIZE);
		if (read_byt < 0 || !buffer[0])
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
	static char	*rem_string;
	char		*res;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_MAX)
		return (NULL);
	rem_string = get_read_string(fd, rem_string);
	if (!rem_string)
		return (NULL);
	res = get_first_line(rem_string);
	rem_string = get_new_rem_str(rem_string);
	return (res);
}
#include <stdio.h>
int	main(void)
{
	int		fd1;
	char	*line;

	fd1 = open("tests/test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	close(fd1);
	return (0);
}