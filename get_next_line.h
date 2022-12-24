/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:23:22 by ahamrad           #+#    #+#             */
/*   Updated: 2022/12/24 13:52:30 by ahamrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif 

char	*get_next_line(int fd);
char	*ft_read_buffer(int fd, char *s);
char	*ft_line(char *s);
int		ft_found_new_line(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);

#endif