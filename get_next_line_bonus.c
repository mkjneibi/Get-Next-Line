/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:21:51 by mealjnei          #+#    #+#             */
/*   Updated: 2022/06/18 13:20:49 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ret_next_line(char *a)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*a)
		return (NULL);
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	while (*a != '\0' && *a != '\n')
		str[j++] = *a++;
	if (*a == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

char	*first_check(int fd, char *a)
{
	char		*str;
	ssize_t		i;
	size_t		m;

	m = BUFFER_SIZE;
	str = malloc(m + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (!ft_strchr(a, '\n') && i)
	{
		i = read(fd, str, m);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		a = ft_strjoin(a, str);
	}
	free(str);
	return (a);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*a[1024];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	a[fd] = first_check(fd, a[fd]);
	if (!a[fd])
		return (NULL);
	str = ret_next_line(a[fd]);
	a[fd] = ft_new_line(a[fd]);
	return (str);
}