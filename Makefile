# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 15:58:29 by baouragh          #+#    #+#              #
#    Updated: 2024/02/17 14:19:23 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address -g3
MAKE = make -C libft

MANDOTORY = mandatory_srcs/commands/add_slash_cmd.c mandatory_srcs/commands/check_cmds.c mandatory_srcs/commands/get_command.c \
			mandatory_srcs/commands/get_env_paths.c mandatory_srcs/commands/get_fullpath.c mandatory_srcs/commands/cmd_mod_check.c \
			mandatory_srcs/commands/skip_first.c mandatory_srcs/tools/check_split.c mandatory_srcs/tools/dup_2.c mandatory_srcs/tools/free_double.c \
			mandatory_srcs/tools/print_err.c mandatory_srcs/tools/strings_count.c mandatory_srcs/fds_manage/create_infile_fd.c \
			mandatory_srcs/fds_manage/create_outfile_fd.c mandatory_srcs/fds_manage/open_fds.c mandatory_srcs/child/call_execve.c \
			mandatory_srcs/child/child.c mandatory_srcs/child/fd_duper.c mandatory_srcs/child/open_pipe.c mandatory_srcs/here_doc/here_doc.c \
			mandatory_srcs/here_doc/open_fds_doc.c mandatory_srcs/return_values/check_out_fd.c mandatory_srcs/return_values/last_outfile_check.c \
			mandatory_srcs/return_values/return_value.c mandatory_srcs/return_values/check_last_cmd.c \
			mandatory_srcs/pipex.c

BONUS = bonus/commands/add_slash_cmd_bonus.c bonus/commands/check_cmds_bonus.c bonus/commands/get_command_bonus.c bonus/commands/get_env_paths_bonus.c \
		bonus/commands/get_fullpath_bonus.c bonus/commands/cmd_mod_check_bonus.c bonus/commands/skip_first_bonus.c \
		bonus/tools/check_split_bonus.c bonus/tools/dup_2_bonus.c bonus/tools/free_double_bonus.c bonus/tools/print_err_bonus.c \
		bonus/tools/strings_count_bonus.c bonus/fds_manage/create_infile_fd_bonus.c bonus/fds_manage/create_outfile_fd_bonus.c \
		bonus/fds_manage/open_fds_bonus.c bonus/child/call_execve_bonus.c bonus/child/child_bonus.c bonus/child/fd_duper_bonus.c \
		bonus/child/open_pipe_bonus.c bonus/here_doc/here_doc_bonus.c bonus/here_doc/open_fds_doc_bonus.c bonus/return_values/check_out_fd_bonus.c \
		bonus/return_values/last_outfile_check_bonus.c bonus/return_values/return_value_bonus.c \
		bonus/return_values/check_last_cmd_bonus.c bonus/pipex_bonus.c


OBJS_M = $(MANDOTORY:.c=.o)
OBJS_B = $(BONUS:.c=.o)

LIBFT = libft/libft.a

NAME = pipex
NAME_BONUS = pipex_bonus

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS_M)
	@$(CC) $(CFLAGS) $(OBJS_M) $(LIBFT) -o $(NAME)

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(LIBFT) $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(NAME_BONUS)

clean:
	@$(MAKE) clean
	@rm -f $(OBJS_M) $(OBJS_B)

fclean: clean
	@$(MAKE) fclean
	@rm -rf $(NAME) $(NAME_BONUS)
$(LIBFT):
	$(MAKE)

re: fclean all

clear:
	clear
	
m: all clean clear

b: bonus clean clear
 
.PHONY: all clean fclean re