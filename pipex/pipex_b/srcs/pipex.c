/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:10:26 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/05 21:42:51 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

t_pipex	*init_data(char *file1, char *file2, pid_t **pids)
{
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	if (!data)
	{
		perror("memory allocation from structure s_pipex failed");
		exit(EXIT_FAILURE);
	}
	data->infile = open(file1, O_RDONLY | O_CREAT, 0644);
	data->outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->pids = pids;
	if (data->infile < 0 || data->outfile < 0)
		error_exit("Error opening files", data->pids);
	return (data);
}

pid_t	*fork_child(t_pipex *data, char **argv, char **envp, int nb_cmd)
{
    pid_t	*pid;
    char	*cmd;
    char	**args;

    args = ft_split(argv[2 + nb_cmd], ' ');
    cmd = find_executable(args[0], envp);
    pid = malloc(sizeof(pid_t));
    if (!pid)
        error_exit("Memory allocation for pid failed", data->pids);
    *pid = fork();
    if (*pid < 0)
        error_exit("Error creating fork/child process", data->pids);
    if (*pid == 0)
    {
        pipe_redirection(nb_cmd, data);
        if (execve(cmd, args, envp) == -1)
        {
            free_args(args);
            free(cmd);
            error_exit("command not found", data->pids);
        }
    }
    free_args(args);
    free(cmd);
    return (pid);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex	*data;
    pid_t	**pids;
    int		i;

    if (argc < 5)
    {
        perror("Invalid argument Usage: ./pipex file1 cmd1 cmd2 file2");
        exit(EXIT_FAILURE);
    }
    pids = malloc(sizeof(pid_t *) * (argc - 3));
    if (!pids)
        error_exit("Memory allocation for pids array failed", NULL);
    data = init_data(argv[1], argv[argc - 1], pids);
    create_pipe(data);
    i = 0;
    while (i < argc - 3)
    {
        pids[i] = fork_child(data, argv, envp, i);
        i++;
    }
    clean_data(data);
    wait_pid(pids, argc - 3);  // Pass the correct number of commands
    i = 0;
    while (i < argc - 3)
    {
        free(pids[i]);
        i++;
    }
    free(pids);
    free(data);
    return (0);
}