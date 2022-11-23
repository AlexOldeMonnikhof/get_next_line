/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:12 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/23 16:17:41 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// char	*make_return_line()

// char	*make_buff(char *str)

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret;
	char		*buff;
	int			bytes;

	if (read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	// buff = (fd)
	// line = make_line
	printf("%zd", read(fd, buff, BUFFER_SIZE));
	return (line);
}


int main(void)
{
	int fd = open("test.c", O_RDONLY);
	get_next_line(fd);
}