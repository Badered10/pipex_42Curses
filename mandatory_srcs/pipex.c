/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/15 16:59:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_fd	fd;
	int		i;

	i = 0;
	if (argc != 5)
		return (print_err("Invaild number of args .", NULL), INV_ARGS);
	fd = open_fds(argc, argv, env, MADANTORY);
	skip_first(&fd, &i, NULL);
	fd.i_place = i;
	cmd_mod_check(fd, argc, argv, env);
	i += 2;
	child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	return (return_value(fd, argc, argv, env));
}

/*
	for this project the the main key of succeed is execve()
	it needs 3 arguments , fullpath of executable file (cmd)
	and the cmd plus its args(double char pointer), and the
	last argument of this func is environment pointer .
	if execve() obtained all its args succefully it will 
	be the end of the current process that call execve() and it will
	lunch new process that replace the old one with the cmd
	we asking for.
	
	pseudocode;
	
	1 ---> check args must be  5; otherways threw error.
	
	2 ---> open fd for infile and outfile ; if fd is right 
	dup it to stdin to pass its content as input to the pipe;
	otherways if fd false open a tmp file to pass its empty content 
	to hundle such cases like command cat taht need input or will hang.
	
	3 ---> check cmds if they are right depending of mods cases,
	print in stderr error if command not found and continue the process
	
	4 ---> create pipe to contact with processes
	
	5 ---> fork the code to make copy of its ressources.
	
	6 --->  in child close inused fds and write output to pipe
	
	7 ---> in parent close inused write to pipe fd , 
	and dup stdin to pipe , and unlink the hidden file if exist.
	
	8 ---> repeat from 4 to 7 but in 6 write to outfile file instead of pipe.
	
	9 ---> in parent wait for all childs processes to finsh
	
	10 ---> if outfile created succeesfully check last cmd 
	if its true ot false , if its true do nothing , else threw the 
	the right return value (126 permission denied)(127 cmd not found)
	or 0 (succeed)
*/