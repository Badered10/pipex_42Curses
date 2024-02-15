/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fullpath_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:07:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/15 17:10:22 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

static char	*founded_cmd(char *argv, char **paths, char **cmd)
{
	char	*fullpath;

	fullpath = get_command(argv);
	if (!fullpath)
	{
		free_double(paths);
		free_double(cmd);
		exit(EXIT_FAILURE);
	}
	return (free_double(paths), free_double(cmd), fullpath);
}

char	*get_fullpath(char *argv, char **env)
{
	int		paths_num;
	char	**cmd;
	char	**paths;
	char	*fullpath;
	int		i;

	i = 0;
	fullpath = NULL;
	paths = get_env_paths(env);
	paths_num = strings_count(paths);
	cmd = ft_split(argv, ' ');
	if (!*cmd)
		return (free_double(cmd), free_double(paths), ft_strdup(""));
	else if (*argv == '/' && access(*cmd, X_OK) == 0)
		return (founded_cmd(argv, paths, cmd));
	else if (access(*cmd, F_OK) == 0 && *argv == '.')
		return (founded_cmd(argv, paths, cmd));
	else
	{
		while (paths_num-- > 0 && !fullpath)
			fullpath = add_slash_cmd(paths[i++], *cmd);
	}
	return (free_double(cmd), free_double(paths), fullpath);
}
