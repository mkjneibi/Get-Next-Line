/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:59:23 by mealjnei          #+#    #+#             */
/*   Updated: 2022/06/18 13:13:09 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_BONUS_H
# define	GET_NEXT_LINE_BONUS_H
#include	<stdio.h> 
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *a);
char	*ret_next_line(char *a);
char	*first_check(int fd, char *s);
char	*ft_free(char **a);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_new_line(char *s);

#endif