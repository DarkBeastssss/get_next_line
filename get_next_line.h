/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:52:21 by amecani           #+#    #+#             */
/*   Updated: 2024/01/24 14:39:30 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// 12345.6789.abcdef.kackavall.8008S

char	*get_next_line(int fd);
char	*we_readin_an_shiet(int fd, char *stash, char *found);
char	*where_da_new_line_at(char *empty, char *stash, int fd, int checky);
char	*ft_strdup(char *s1, int farewell);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*custom(char *s1, char *s2, int simply_return_s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
// setup in new phone incase it gets stolen retienving it