/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_outfile_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:22 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 10:27:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	create_outfile_fd(int argc, t_fd *fd, char **argv, char **env)
{
	(void)env;
	fd->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd->outfile < 0)
		return (3);
	return (0);
}
