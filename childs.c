/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:43:48 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/13 18:26:04 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int macron, char **argv, char **env)
{
	int		fd;
	char	**args;
	char	*cmd;
	char	*path;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Input File error");
	path = getpath(env);
	dup2(fd, STDIN_FILENO);
	close(fd);
	args = ft_split(argv[2], ' ');
	cmd = getcmd(path, args[0]);
	if (!cmd)
		exit(0);
	dup2(macron, STDOUT_FILENO);
	execve(cmd, args, env);
	error("Error command one");
}

void	child2(int macron, char **argv, char **env)
{
	int		fd;
	char	**args;
	char	*cmd;
	char	*path;

	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0)
		error("Output file error");
	path = getpath(env);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	args = ft_split(argv[3], ' ');
	cmd = getcmd(path, args[0]);
	if (!cmd)
		exit(0);
	dup2(macron, STDIN_FILENO);
	execve(cmd, args, env);
	error("Error command two");
}
