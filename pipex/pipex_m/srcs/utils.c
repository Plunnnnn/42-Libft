/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:45:01 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/04 16:53:37 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(t_pipex *data)
{
	if (pipe(data->pipe_fd) == -1)
		error_exit("failed to create pipe");
}

void	wait_pid(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	clean_data(t_pipex *data)
{
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	close(data->infile);
	close(data->outfile);
}

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
