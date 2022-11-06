/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:40:00 by osajide           #+#    #+#             */
/*   Updated: 2022/11/04 12:14:35 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	int	*p;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (p == 0)
		return (p);
	else
		ft_bzero(p, count * size);
	return (p);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	char			*tcs;

	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	tcs = (char *)s;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	if (start >= 0)
	{
		i = 0;
		while (tcs[start] && i < len)
			sub[i++] = tcs[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (0);
}

char *just_line(char *buffer)
{
	int i;
	char *line;
	char *remainer;

	i = 0;
	remainer = ft_strchr(buffer, '\n');
	line = malloc(ft_strlen(buffer) - ft_strlen(remainer) + 1);
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
