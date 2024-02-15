/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_outfile_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:50:21 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/14 14:22:48 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	last_outfile_check(int argc, char **argv)
{
	int	len;

	len = ft_strlen(argv[argc - 2]) + ft_strlen(argv[argc -1]);
	len = ft_strncmp(argv[argc - 2], argv[argc - 1], len);
	return (len);
}
