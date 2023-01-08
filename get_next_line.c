/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:12 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/01/08 15:45:20 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*make_output_line(char *raw_line)
{
	size_t	i;
	char	*new_line;

	i = 0;
	if (!raw_line[0])
		return (NULL);
	while (raw_line[i] != '\n' && raw_line[i])
		i++;
	if (raw_line[i] == '\0')
		return (raw_line);
	i++;
	new_line = (char *)malloc((i + 1) * sizeof(char));
	if (!new_line)
		return (free(raw_line), NULL);
	new_line[i] = 0;
	while (i > 0)
	{
		i--;
		new_line[i] = raw_line[i];
	}
	return (new_line);
}

char	*make_raw_line(char *return_line, int fd)
{
	int		bytes_read;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 42;
	while (!ft_strchr(return_line, '\n') && bytes_read)	
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), NULL);
		buff[bytes_read] = 0;
		return_line = ft_strjoin(return_line, buff);
	}
	free(buff);
	return (return_line);
}

char	*make_leftover_line(char *return_line)
{
	size_t	i;

	i = 0;
	if (!return_line[0])
		return (NULL);
	while (return_line[i] != '\n')
	{
		if (return_line[i] == '\0')
			return (NULL);
		i++;
	}
	return (return_line + i + 1);
}


char	*get_next_line(int fd)
{
	static char	*line;
	char		*output_line;

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	line = make_raw_line(line, fd);
	if (!line)
		return (NULL);
	// printf("rawoutput=%s\n", line);
	output_line = make_output_line(line);
		// printf("output=%s", output_line);
	line = make_leftover_line(line);
	return (output_line);
}

// int main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line;
// 	int i = 1;

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("line %d: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// }
