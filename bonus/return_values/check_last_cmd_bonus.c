/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_cmd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/18 10:44:08 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	check_last_cmd(char *cmd_set, int not_same, char **env)
{
	char	*last_cmd;
	char	**env_path;

	env_path = get_env_paths(env);
	last_cmd = get_fullpath(cmd_set, env);
	if (!last_cmd && *cmd_set == '.')
	{
		free(last_cmd);
		last_cmd = get_command(cmd_set);
	}
	if ((access(last_cmd, F_OK) && *cmd_set != '\0') || not_same == 0)
		return (free(last_cmd), free_double(env_path), NOT_FOUND);
	else
	{
		if (access(last_cmd, X_OK) && *cmd_set != '\0')
			return (free(last_cmd), free_double(env_path), PERMISSION_DENIED);
	}
	if (!env_path && *cmd_set == '\0')
		return (free(last_cmd), NOT_FOUND);
	return (free_double(env_path), free(last_cmd), 0);
}
