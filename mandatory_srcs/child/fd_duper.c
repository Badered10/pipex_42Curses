/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_duper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:12:23 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 09:33:21 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

void	fd_duper(t_fd fd, int mod, int *pfd)
{
	if (mod == LAST_CMD)
	{
		close(pfd[1]);
		close(pfd[0]);
		if (dup_2(fd.outfile, 1))
			exit(EXIT_FAILURE);
	}
	else
	{
		close(fd.outfile);
		close(pfd[0]);
		if (dup_2(pfd[1], 1))
			exit(EXIT_FAILURE);
	}
}
