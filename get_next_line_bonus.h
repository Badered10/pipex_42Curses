/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:25:19 by baouragh          #+#    #+#             */
/*   Updated: 2024/01/19 18:34:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char				*get_next_line(int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
char	            *ft_csubstr(char *s, unsigned int start, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char	            *ft_cstrjoin(char *s1, char *s2);
#endif