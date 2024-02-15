/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:07:44 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 01:33:48 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

void	print_err(char *message, char *word)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd(word, 2);
	write(2, "\n", 1);
}
