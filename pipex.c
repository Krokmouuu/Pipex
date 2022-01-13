/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:38:56 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/13 13:55:36 by bleroy           ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	char	*path;
	int		pid1;
	int		pid2;
	int		macron[2];

	if (argc == 5)
	{
		pipex.fd[0] = open(argv[1], O_RDONLY);
		if (pipex.fd[0] < 0)
			return (0);
		pipex.fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (pipex.fd[1] < 0)
			return (0);
		if (pipe(macron) == -1)
			return (0);
		path = getpath(env);
		pid1 = fork();
		if (pid1 < 0)
			return (0);
		if (pid1 == 0)
			child1(macron[1], pipex, argv, path, env);
		pid2 = fork();
		if (pid2 < 0)
			return (0);
		if (pid2 == 0)
			child2(macron[0], pipex, argv, path, env);
		waitpid(pid1, NULL, 0);
	}
	return (0);
}
