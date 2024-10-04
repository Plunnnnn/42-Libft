/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:40:33 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/04 17:15:38 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_executable(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_args(paths);
			return (path);
		}
		free(path);
	}
	free_args(paths);
	return (0);
}

void	pipe_redirection(int nb_cmd, t_pipex *data)
{
	if (nb_cmd == 1)
	{
		dup2(data->infile, STDIN_FILENO);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
	}
	else if (nb_cmd == 2)
	{
		dup2(data->pipe_fd[0], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}
