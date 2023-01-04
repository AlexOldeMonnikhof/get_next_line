/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:12 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/01/04 19:31:06 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*make_output_line(char *return_line)
{
	size_t	i;
	size_t	length_new_line;
	char	*new_line;

	i = 0;
	while (return_line[i] != '\n' && return_line[i])
		i++;
	if (return_line[i] == '\0')
	{
		// printf("hoi\t");
		return (NULL);
	}
	length_new_line = i + 1;
	new_line = (char *)malloc((length_new_line + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < length_new_line)
	{
		new_line[i] = return_line[i];
		i++;
	}
	new_line[i] = 0;
	// free(return_line);
	return (new_line);
}

char	*make_return_line(char *return_line, int fd)
{
	int		bytes_read;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = -1;
	while (!ft_strchr(return_line, '\n') && bytes_read)	
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), NULL);
		buff[bytes_read] = 0;
		return_line = ft_strjoin(return_line, buff);
	}
	free(buff);
	// return_line[4] = '\0';
	return (return_line);
}

char	*make_leftover_line(char *return_line)
{
	size_t	i;
	size_t	length_new_line;
	char	*new_line;

	i = 0;
	if (!return_line)
		return (NULL);
	while (return_line[i] != '\n')
	{
		if (return_line[i] == '\0')
			return (return_line);
		i++;
	}
	length_new_line = ft_strlen(return_line) - i - 1;
	new_line = (char *)malloc((length_new_line + 1) * sizeof(char));
	new_line[0] = 0;
	new_line = ft_strjoin(new_line, return_line + i + 1);
	if (!new_line)
		return (NULL);
	return (free(return_line), new_line);
}


char	*get_next_line(int fd)
{
	static char	*line;
	char		*output_line;
	char		*return_line;

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	line = make_return_line(line, fd);
	// printf("%s", line);
	output_line = make_output_line(line);
	// printf("%s", output_line);
	if (!output_line)
	{
		return (line);
	}
	line = make_leftover_line(line);
	// if (!line)
	// 	return (line);
	return (output_line);
}


int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char *line;

	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	line = get_next_line(fd);
	// printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}