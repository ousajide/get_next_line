/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:36:05 by osajide           #+#    #+#             */
/*   Updated: 2022/11/07 14:50:19 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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
void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}