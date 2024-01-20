/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:27:58 by baouragh          #+#    #+#             */
/*   Updated: 2024/01/19 18:35:23 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "libft.h"


char	*ft_cstrjoin(char *s1, char *s2)
{
	char	*new;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	ft_memmove(new, s1, ft_strlen(s1));
	ft_memmove(new + ft_strlen(s1), s2, ft_strlen(s2));
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (new);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)b;
	i = 0;
	while (i < len)
		temp[i++] = (unsigned char)c;
	return (b);
}
