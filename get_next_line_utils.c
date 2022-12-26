/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:23:16 by ahamrad           #+#    #+#             */
/*   Updated: 2022/12/26 09:30:26 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	// free(s1);
	return (str);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*new;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1)
// 	{
// 		s1 = malloc(sizeof(char));
// 		if (!s1)
// 			return (NULL);
// 		s1[0] = '\0';
// 	}
// 	if (!s2)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
// 	if (!new)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		new[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		new[i + j] = s2[j];
// 		j++;
// 	}
// 	new[i + j] = '\0';
// 	// free(s1);
// 	return (new);
// }
