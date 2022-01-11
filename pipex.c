/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:38:56 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/11 18:20:47 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char **env)
{
	char	*path;
	int		i;

	i = -1;
	while (!ft_strnstr(*env, "PATH=", 5))
		env++;
	path = *env;
	return (path + 5);
}

char	*getcmd(char **argv, char *path)
{
	char	**split;
	char	*cmd;
	int		i;
	char	**args;

	i = 0;
	split = ft_split(path, ':');
	args = ft_split(*argv, ' ');
	while (split[i])
	{
		cmd = ft_strjoin(split[i], argv[2]);
		if (!access(cmd, 0))
			return (cmd);
		free (cmd);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	char	*path;
	char	*cmd;
	int		pid1;
	int		pid2;

	if (argc == 5)
	{
		fd[0] = open(argv[1], O_RDONLY);
		fd[1] = open(argv[5], O_RDWR);
		if (pipe(fd) == -1)
			return (0);
		path = getpath(env);
		cmd = getcmd(argv, path);
		printf("%s\n", cmd);
		pid1 = fork();
		if (pid1 < 0)
			return (0);
		pid2 = fork();
		if (pid2 < 0)
			return (0);
		waitpid(pid1, NULL, 0);
	}
	return (0);
}
