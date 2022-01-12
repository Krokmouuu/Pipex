/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:43:48 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/12 17:52:37 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int fd, char **argv, char *path, char **env)
{
	char	**args;
	char	*cmd;

	dup2(fd, STDIN_FILENO);
	close(fd);
	args = ft_split(argv[2], ' ');
	cmd = getcmd(path, args[0]);
	if (!cmd)
		exit(0);
	execve(cmd, args, env);
}

void	child2(int fd, char **argv, char *path, char **env)
{
	char	**args;
	char	*cmd;

	dup2(fd, STDOUT_FILENO);
	close(fd);
	args = ft_split(argv[3], ' ');
	cmd = getcmd(path, args[0]);
	if (!cmd)
		exit(0);
	execve(cmd, args, env);
}
