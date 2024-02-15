/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:20:47 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/15 17:17:18 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

void	check_split(char **cmd, char *word)
{
	if (!cmd)
	{
		print_err("malloc failed in ft_split !!", word);
		if (!word)
			ft_putstr_fd("NULL\n", 2);
		exit (EXIT_FAILURE);
	}
}
