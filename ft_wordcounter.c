/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:13:01 by baouragh          #+#    #+#             */
/*   Updated: 2024/01/18 12:30:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordcounter(const char *s, char c)
{
	char	*x;
	int		words;

	words = 0;
	x = (char *)s;
	while (*x)
	{
		while (*x == c && *x)
			x++;
		if (*x)
		{
			while (*x != c && *x)
				x++;
			words++;
		}
	}
	return (words);
}