/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:20:11 by osajide           #+#    #+#             */
/*   Updated: 2022/11/06 13:40:14 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

char *just_line(char *buffer)
{
	int i;
	char *line;

	i = 0;
	if(*buffer == '\n')
		buffer++;
	//printf("BEFORE: %s\n", buffer);
	while (buffer[i] && buffer[i]!= '\n')
		i++;
	line = malloc(i  + 2);
	i = 0;
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	//printf("AFTER: %s\n", buffer);
	line[i++] = '\n';
	line[i] = '\0';
	
	// free(buffer);
	return (line);
}

char *fremainer(char *buffer)
{
	int i;
	char *buff;
	char *remainer;

	if (!buffer)
	return 0;
	if(*buffer == '\n')
		buffer++;
	i = 0;
	remainer = ft_strchr(buffer, '\n');
	buff = ft_strdup(remainer);
	while (buffer[i] && buffer[i] != '\n')
	{ 
		buff[i] = remainer[i];
		i++;
	}
	buff[i] = '\0';
	// printf("REST : %s\n",remainer);
	// printf("BUFF: %s\n", buff);
	// free(buffer);
	return (buff);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	char *s;
	int i;
	int readline;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return 0;
	i = 0;
	s = malloc(BUFFER_SIZE + 1);
	readline = 1;
	while(readline > 0 && !ft_strchr(s, '\n'))
	{
		readline = read(fd, s, BUFFER_SIZE);
		//printf("S:%s\n", s);
		if (readline == 0)
			break;
		printf("read:%d\n", readline);
		// if (readline < 0)
		// {
		// 	free(s);
		// 	return (NULL);
		// }
		s[BUFFER_SIZE] = '\0';
		printf("string readed: %s\n", s);
		buffer = ft_strjoin(buffer, s);
		//  if (ft_strchr(s, '\n'))
		//  	break;
	}
	//free(s);
	//printf("BUFFER BEFORE: %s\n", buffer);
	if (buffer == NULL)
		return (NULL);
	line = just_line(buffer);
	//  printf("LINE: %s", line);
	//  printf("BUFFER AFTER: %s\n", buffer);
	buffer = fremainer(buffer);
	//printf("BREMAIN: %s\n", buffer);
	return (line);
}

int main()
{	
	int fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
	return (0);
}