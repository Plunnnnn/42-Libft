/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:45:01 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/05 21:42:34 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(t_pipex *data)
{
	if (pipe(data->pipe_fd) == -1)
		error_exit("failed to create pipe", data->pids);
}

void wait_pid(pid_t **pids, int nb_cmd)
{
    int i = 0;
    
    while (i < nb_cmd)
    {    
        waitpid(*pids[i], NULL, 0);
        i++;
    }
}

void	clean_data(t_pipex *data)
{
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	close(data->infile);
	close(data->outfile);
}

void	error_exit(char *str, pid_t **pids)
{
	int	i;

	i = 0;
	while (pids[i])
	{
		free(pids[i]);
		i++;
	}
	free(pids);
	perror(str);
	exit(EXIT_FAILURE);
}
