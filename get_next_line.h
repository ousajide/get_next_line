/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:32:39 by osajide           #+#    #+#             */
/*   Updated: 2022/11/07 14:49:38 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>
#include<fcntl.h>

#define BUFFER_SIZE 5

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
char *just_line(char *buffer);
char *fremainer(char *buffer);
char *get_next_line(int fd);

#endif