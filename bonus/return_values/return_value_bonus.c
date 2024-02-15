/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:56:58 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/14 14:22:52 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	return_value(t_fd fd, int argc, char **argv, char **env)
{
	int	return_num;

	return_num = last_outfile_check(argc, argv);
	if (!fd.check_out)
		return (check_last_cmd(argv[argc - 2], return_num, env));
	return (check_out_fd(fd.check_out, argc, argv));
}
