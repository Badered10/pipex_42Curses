/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:47:22 by baouragh          #+#    #+#             */
/*   Updated: 2024/01/19 18:35:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	if (src > dst)
	{
		if (!destination && !source)
			return (NULL);
		if (destination == source)
			return (dst);
		while (len--)
			*destination++ = *source++;
		return (dst);
	}
	while (len != 0)
	{
		destination[len - 1] = source[len - 1];
		len--;
	}
	return ((void *)destination);
}
