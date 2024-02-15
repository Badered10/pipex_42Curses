/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mod_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:53:38 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/14 14:22:34 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

void	cmd_mod_check(t_fd fd, int argc, char **argv, char **env)
{
	fd.check_sum = fd.check_in + fd.check_out;
	check_cmds(fd, argc, argv, env);
}
