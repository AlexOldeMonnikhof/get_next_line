/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:36:48 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/23 14:47:56 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int len = 5;
	char *test;

	test = ft_calloc(len + 1, sizeof(char));
	if (!test)
		printf("faal\n");
	else
		printf("nice\n");
}
