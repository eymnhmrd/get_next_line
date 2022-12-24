/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:23:20 by ahamrad           #+#    #+#             */
/*   Updated: 2022/12/24 16:19:48 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *s)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * ft_strlen(s) - i + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			i++;
		rest[j++] = s[i++];
	}
	free(s);
	s = NULL;
	return (rest);
}

char	*ft_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if(s[i] == '\n')
		res[i++] = '\n';
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
	while (readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(s);
			return (NULL);
		}
		buff[readed] = '\0';
		s = ft_strjoin(s, buff);
		if (ft_found_new_line(s, '\n'))
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
	line = ft_line(s_str);
	s_str = ft_save(s_str);
	return (line);
}
