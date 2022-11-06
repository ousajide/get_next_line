/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgetnext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:09:02 by osajide           #+#    #+#             */
/*   Updated: 2022/11/05 15:41:39 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 20

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*join;

	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	
	j = 0;
	while (s1 && ((char *)s1)[i])
	{
		join[i] = ((char *)s1)[i];
		i++;
	}
	while (s2 && ((char *)s2)[j])
	{
		join[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	while ((char)str[i] != (char )c && str[i] != '\0')
		i++;
	if ((char)str[i] == (char)c)
	{
		p = (char *)&str[i];
		return (p);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		slen;
	int		i;
	char	*cs1;

	slen = (ft_strlen(s1));
	dup = malloc(slen + 1);
	i = 0;
	if (dup == NULL)
		return (0);
	cs1 = (char *)s1;
	while (i < slen)
	{
		dup[i] = cs1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *just_line(char *buffer)
{
	int i;
	char *line;

	i = 0;
	if(*buffer == '\n')
		buffer++;
	while (buffer[i] && buffer[i]!= '\n')
	{
		i++;
	}
	line = malloc(i  + 2);
	i = 0;
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	//free(buffer);
	return (line);
}

char *fremainer(char *buffer)
{
	int i;
	char *buff;
	char *remainer;

	if (!buffer)
	return 0;
	i = 0;
	remainer = ft_strchr(buffer, '\n');
	buff = ft_strdup(remainer);
	while (buffer[i] != '\n' && buffer[i])
	{
		buff[i] = remainer[i];
		i++;
	}
	buff[i] = '\0';
	//printf("%s\n", buff);
	//free(buffer);
	return (buff);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	//static char *remain;
	char *s;
	int i;
	int readline;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return 0;
	i = 0;
	s = malloc(BUFFER_SIZE + 1);
	readline = 1;
	while(readline > 0)
	{
		readline = read(fd, s, BUFFER_SIZE);
		if (readline < 0)
		{
			free(s);
			return (NULL);
		}
		s[BUFFER_SIZE] = '\0';
		buffer = ft_strjoin(buffer, s);
		if (ft_strchr(s, '\n'))
			break;
	}
	//free(s);
	
	//line = just_line(buffer);
	line = just_line(buffer);
	//printf("%s\n", buffer);
	buffer = fremainer(buffer);
	return (line);
}

int main()
{	
	int fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	
	return (0);
}
