/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_infile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:00 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/13 22:54:41 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	create_infile_fd(t_fd *fd, char **argv)
{
	fd->infile = open(argv[1], O_RDONLY);
	if (fd->infile < 0)
	{
		if (access(argv[1], F_OK))
			print_err("pipex: no such file or directory: ", argv[1]);
		else
			print_err("pipex: permission denied: ", argv[1]);
		fd->check_in = -1;
		return (1);
	}
	return (0);
}
