/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:38:56 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/12 18:12:55 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char **env)
{
	char	*path;

	while (!ft_strnstr(*env, "PATH=", 5))
		env++;
	path = *env;
	return (path + 5);
}

char	*getcmd(char *path, char *args)
{
	char	**split;
	char	*cmd;
	int		i;

	i = 0;
	split = ft_split(path, ':');
	while (split[i])
	{
		cmd = ft_strjoin(split[i], args);
		if (!access(cmd, 0))
			return (cmd);
		free (cmd);
		i++;
	}
	return (NULL);
}
/*
int	process(char **argv, char *path)
{
	int	pid1;
	int	pid2;

	pid1 = fork();
	if (pid1 < 0)
		return (0);
	pid2 = fork();
	if (pid2 < 0)
		return (0);
	if (pid1 == 0)
		child1(argv, path);
	if (pid2 == 0)
		child2(argv, path);
	waitpid(pid1, NULL, 0);
	return (0);
}*/

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	char	*path;
	int		pid1;
	int		pid2;

	if (argc == 5)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			return (0);
		fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (fd[0] < 0)
			return (0);
		pipe(fd);
		if (pipe(fd) == -1)
			return (0);
		path = getpath(env);
		pid1 = fork();
		if (pid1 < 0)
			return (0);
		pid2 = fork();
		if (pid2 < 0)
			return (0);
		printf("OwO");
		if (pid1 == 0)
			child1(fd[0], argv, path, env);
		printf("UwU");
		if (pid2 == 0)
			child2(fd[1], argv, path, env);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
