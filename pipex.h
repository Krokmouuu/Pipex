/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:08:22 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/12 18:14:43 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define STDIN 0

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

void	child1(int fd, char **argv, char *path, char **env);
void	child2(int fd, char **argv, char *path, char **env);

char	*getcmd(char *path, char *args);
char	*getpath(char **env);
int		process(char **argv, char *path);
int		main(int argc, char **argv, char **f);

#endif