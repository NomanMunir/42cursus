/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:01:08 by nmunir            #+#    #+#             */
/*   Updated: 2023/08/05 16:33:42 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_string(int fd, char *rem_string)
{
	char	*buffer;
	int		read_byt;

	read_byt = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read_byt != 0 && !ft_strchr(rem_string, '\n'))
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
	static char	*rem_string;
	char		*res;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rem_string = get_read_string(fd, rem_string);
	if (!rem_string)
		return (NULL);
	res = get_first_line(rem_string);
	rem_string = get_new_rem_str(rem_string);
	return (res);
}

// int	main(void)
// {
// 	int		fd1;
// 	char	*line;

// 	fd1 = open("get_next_line/tests/test.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	printf("%s", line);
// 	free(line);
// 	close(fd1);
// 	return (0);
// }
