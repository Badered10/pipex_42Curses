/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/17 15:02:48 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		cmds;
	t_fd	fd;
	int		i;
	int		doc;

	i = 0;
	if (argc < 5)
		return (ft_putstr_fd("Not enough arguments !", 2), INV_ARGS);
	doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]));
	cmds = argc - (4);
	if (!doc)
		here_doc(&fd, argv, &i, &cmds);
	fd = open_fds(argc, argv, env, doc);
	skip_first(&fd, &i, &cmds);
	cmd_mod_check(fd, argc, argv, env);
	i += 2;
	while (cmds--)
		child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (!waitpid(-1, NULL, 0))
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
	

	almost same algo as madantory part despite checking in args 
	msut be at least 5 and (here_doc case and multiple pipes)...
	
	pseudocode:
	
	1 ---> check args must be at least 5; otherways threw error.
	
	2 ---> if the arg 2 not "here_doc"open fd for infile 
	and outfile ; if fd is right dup it to stdin to pass its content
	as input to the pipe; otherways if fd false open a tmp file to
	pass its empty content to hundle such cases like command cat taht
	need input or will hang.
	
	2.0 --->in here_doc case open fd for a hidden file to write in it 
	the input that user write in stdin, and open outfile file.
	
	2.1 ---> in heredoc case also re open the hidden file to get a new file
	pointer the offset of it will be 0 to past it as input to the first cmd.
	
	2.2 ---> if fisrt cmd not valid skip it by increment index i by one and 
	deincrement the cmds by one and set structer index to be equal to
	current i.
	
	3 ---> check cmds if they are right depending of mods cases,
	print in stderr error if command not found and continue the process
	
	4 ---> create pipe to contact with processes
	
	5 ---> fork the code to make copy of its ressources.
	
	6 --->  in child close inused fds and write output to pipe
	
	7 ---> in parent close inused write to pipe fd , 
	and dup stdin to pipe , and unlink the hidden file if exist.
	
	8 ---> repeat from 4 to 7 (cmds -1) times 
	
	8.1 ----> in last cmd case in 6 write to outfile file instead of pipe.
	
	9 ---> in parent wait for all childs processes to finsh
	
	10 ---> if outfile created succeesfully check last cmd 
	if its true ot false , if its true do nothing , else threw the 
	the right return value (126 permission denied)(127 cmd not found)
	or 0 (succeed)
*/