/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:07:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/01/19 18:28:01 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*copy;
	size_t	lenth;

	if (!s1)
		return (ft_strdup(""));
	lenth = ft_strlen(s1);
	copy = (char *)malloc(lenth + 1);
	if (!copy)
	{
		return (NULL);
	}
	ft_memmove(copy, s1, lenth);
	copy[lenth] = '\0';
	return (copy);
}
