/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/14 14:01:29 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	check_last_cmd(char *cmd_set, int not_same, char **env)
{
	char	*last_cmd;

	last_cmd = get_command(cmd_set);
	if (access(last_cmd, F_OK))
	{
		free(last_cmd);
		last_cmd = get_fullpath(cmd_set, env);
	}
	if (access(last_cmd, F_OK) || not_same == 0)
		return (free(last_cmd), NOT_FOUND);
	else
	{
		if (access(last_cmd, X_OK))
			return (free(last_cmd), PERMISSION_DENIED);
	}
	return (0);
}
