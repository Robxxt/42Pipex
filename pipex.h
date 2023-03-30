/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:21:33 by rdragan           #+#    #+#             */
/*   Updated: 2023/03/29 19:07:42 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		check_wait(int w);
int		compare_strings(char *s1, char *s2);
int		get_bin_index(char *env[]);
char	*get_bin_path(char *env[], char *arg);
char	**format_cmd(char *cmd, char *bin_path);
int		first_quotation_mark(char *s);
int		l_q_mark(char *s);
int		first_word(char *s);

#endif