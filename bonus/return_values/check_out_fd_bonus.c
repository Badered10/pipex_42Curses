/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_out_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:54:44 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/14 14:01:02 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	check_out_fd(int check, int argc, char **argv)
{
	if (check)
	{
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		return (1);
	}
	return (0);
}
