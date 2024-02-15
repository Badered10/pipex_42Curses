/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:13:44 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 01:32:45 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

char	*get_command(char *argv)
{
	char	*cmd;
	int		i;

	i = 0;
	while (argv[i] != ' ' && argv[i] != '\0')
		i++;
	cmd = malloc(i + 1);
	if (!cmd)
	{
		perror("malloc");
		return (NULL);
	}
	ft_memmove(cmd, argv, i);
	cmd[i] = '\0';
	return (cmd);
}
