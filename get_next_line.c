/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:23:20 by ahamrad           #+#    #+#             */
/*   Updated: 2022/12/26 11:34:53 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_rest(char *s)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * ft_strlen(s) - i + 1);
	if (!rest)
		return (NULL);
	j = 0;
	i++;
	while (s[i])
	{
		rest[j] = s[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	free(s);
	return (rest);
}

char	*ft_return_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		res = malloc(sizeof(char) * i + 2);
	else
		res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_read_buffer(int fd, char *s)
{
	char	*buff;
	char	*tmp;
	int		readed;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == 0)
		{
			free(buff);
			return (s);
		}
		if (readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		tmp = s;
		s = ft_strjoin(s, buff);
		free(tmp);
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_str = ft_read_buffer(fd, s_str);
	if (!s_str)
		return (NULL);
	line = ft_return_line(s_str);
	s_str = ft_get_rest(s_str);
	return (line);
}
