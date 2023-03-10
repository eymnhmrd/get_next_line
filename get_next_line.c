/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:23:20 by ahamrad           #+#    #+#             */
/*   Updated: 2023/01/02 20:52:31 by ahamrad          ###   ########.fr       */
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
	if (s[i] == '\n')
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
	i = -1;
	while (s[++i] && s[i] != '\n')
		res[i] = s[i];
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_read_buffer(int fd, char *s)
{
	char	*buff;
	int		readed;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readed = 1;
	while (readed > 0 && !ft_strchr(s, '\n'))
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == 0)
			break ;
		if (readed == -1)
			return (free(buff), free(s), NULL);
		buff[readed] = '\0';
		s = ft_strjoin(s, buff);
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
	if (!s_str || *s_str == '\0')
		return (free(s_str), s_str = NULL, NULL);
	line = ft_return_line(s_str);
	s_str = ft_get_rest(s_str);
	return (line);
}
