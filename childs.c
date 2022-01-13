/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:43:48 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/13 13:56:05 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int macron, t_pipex pipex, char **argv, char *path, char **env)
{
	char	**args;
	char	*cmd;

	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[0]);
	args = ft_split(argv[2], ' ');
	cmd = getcmd(path, args[0]);
	if (!cmd)
		exit(0);
	dup2(macron, STDOUT_FILENO);
	execve(cmd, args, env);
}

void	child2(int macron, t_pipex pipex, char **argv, char *path, char **env)
{
	char	**args;
	char	*cmd;

	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	args = ft_split(argv[3], ' ');
	cmd = getcmd(path, args[0]);
	if (!cmd)
		exit(0);
	dup2(macron, STDIN_FILENO);
	execve(cmd, args, env);
}
