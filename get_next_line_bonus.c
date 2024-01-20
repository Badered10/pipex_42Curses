/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:36:59 by baouragh          #+#    #+#             */
/*   Updated: 2024/01/19 18:33:47 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "libft.h"

char	*ft_csubstr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l_total;
	size_t	l_sub;

	if (!*s)
		return (NULL);
	l_total = ft_strlen(s);
	l_sub = l_total - start;
	if (start > l_total || !len)
		return (ft_strdup("\n"));
	if (len > l_sub)
		len = l_sub;
	if (ft_strchr(s, '\n') != NULL && s[0] != '\n' && s[1] != '\0')
		len += 2;
	else
		len += 1;
	res = (char *)malloc(sizeof(char) * (len));
	if (!res)
		return (free(s), (NULL));
	ft_memmove(res, s + start, len);
	res[len - 1] = '\0';
	return (res);
}

char	*ft_rest(char *store)
{
	char	*nplace;
	char	*eplace;
	char	*rest;
	int		len;

	len = 0;
	nplace = ft_strchr(store, '\n');
	eplace = ft_strchr(store, '\0');
	if (!nplace || !eplace)
		return (free(store), (NULL));
	len = (eplace - nplace);
	if (len)
		rest = malloc(sizeof(char) * len);
	else
		return (free(store), (NULL));
	if (!rest)
		return (free(store), (NULL));
	ft_memmove(rest, nplace + 1, len);
	rest[len - 1] = '\0';
	return (free(store), (rest));
}

char	*get_store(int fd, char *store, char *res, char *buffer)
{
	int	check;

	check = 1;
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(store), free(buffer), NULL);
	while (check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if ((check == 0 && ((!store) || store[0] == '\0')) || check == -1)
			return (free(store), free(buffer), NULL);
		buffer[check] = 0;
		res = ft_strdup(store);
		if (!res)
			return (free(store), free(buffer), NULL);
		if (store)
			free(store);
		store = ft_cstrjoin(res, buffer);
		if (store[0] == '\0' && res)
			return (free(res), free(store), free(buffer), NULL);
		free(res);
		if (ft_strchr(store, '\n') != NULL)
			break ;
	}
	return (free(buffer), store);
}

char	*get_next_line(int fd)
{
	static char	*store[FD_SETSIZE];
	char		*buffer;
	char		*res;
	int			check;

	res = NULL;
	check = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(store[fd]), NULL);
	store[fd] = get_store(fd, store[fd], res, buffer);
	if (store[fd] == '\0')
		return (free(store[fd]), (NULL));
	res = ft_strchr(store[fd], '\n');
	if (res)
		check = (res - store[fd]);
	else
		check = ft_strlen(store[fd]);
	res = ft_csubstr(store[fd], 0, check);
	store[fd] = ft_rest(store[fd]);
	return (res);
}
