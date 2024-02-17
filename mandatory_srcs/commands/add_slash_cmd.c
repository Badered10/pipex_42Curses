/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_slash_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:03:43 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/17 14:52:39 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

char	*add_slash_cmd(char *path, char *cmd)
{
	char	*a_path;
	char	*fullpath;

	a_path = (ft_strjoin(path, "/"));
	fullpath = ft_strjoin(a_path, cmd);
	if (!access(fullpath, X_OK))
		return (free(a_path), fullpath);
	else
		return (free(fullpath), free(a_path), NULL);
}
