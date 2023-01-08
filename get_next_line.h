/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:27 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/01/08 13:48:11 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#include <unistd.h>
#include <stdlib.h>

char		*get_next_line(int fd);
char		*make_output_line(char *raw_line);
char		*make_raw_line(char *return_line, int fd);
char		*make_leftover_line(char *return_line);
// utils
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char  *s1, char  *s2);
size_t		ft_strchr(char *s, char c);
void	ft_free(char *s1, char *s2);

#endif