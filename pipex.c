/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:38:56 by bleroy            #+#    #+#             */
/*   Updated: 2022/01/13 18:24:23 by bleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	error(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
	exit(0);
}

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
	error("Command or path not available");
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	int		pid1;
	int		pid2;
	int		macron[2];

	if (argc != 5)
		error("Missing or Too much arguments");
	if (pipe(macron) == -1)
		error("Problem pipe");
	pid1 = fork();
	if (pid1 < 0)
		error("Error fork one");
	if (pid1 == 0)
		child1(macron[1], argv, env);
	close(macron[1]);
	pid2 = fork();
	if (pid2 < 0)
		error("Error fork two");
	if (pid2 == 0)
		child2(macron[0], argv, env);
	close(macron[0]);
	close(macron[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
