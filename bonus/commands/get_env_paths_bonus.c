/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_paths_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:03:04 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/16 16:24:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

char	**get_env_paths(char **env)
{
	char	**res;

	if (!env)
		return (NULL);
	while (*env && !ft_strnstr(*env, "PATH", 5))
		env++;
	if (!*env)
		return (NULL);
	res = ft_split(*env, ':');
	check_split(res,*env);
	ft_memmove(*res, ft_strchr(*res, '/'), ft_strlen(*res));
	return (res);
}
