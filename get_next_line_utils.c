/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:34:57 by mealjnei          #+#    #+#             */
/*   Updated: 2022/06/18 12:48:59 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *a)
{
	size_t	k;

	k = 0;
	while (a[k])
		k++;
	return (k);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	m;

	m = (char)c;
	str = (char *)s;
	if (!str)
		return (NULL);
	while (*str != '\n')
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		mk;
	int		ab;
	char	*str;

	mk = 0;
	ab = 0;
	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[mk])
		str[ab++] = s1[mk++];
	mk = 0;
	while (s2[mk])
		str[ab++] = s2[mk++];
	str[ab] = '\0';
	free(s1);
	return (str);
}

char	*ft_new_line(char *a)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	if (!a[i])
	{
		free(a);
		return (NULL);
	}
	str = malloc((ft_strlen(a) - i + 1)); //length of s - (new line we already found before) + (null)
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (a[i] != '\0')
		str[j++] = a[i++];
	str[j] = '\0';
	free(a);
	return (str);
}
