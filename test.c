/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:36:48 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/23 17:32:35 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int len = 5;
	char *test;
	int fd = open("text.txt", O_RDONLY);
	test = calloc(len + 1, sizeof(char));
	read(fd, test, 100);
	printf("%s", test);
}
