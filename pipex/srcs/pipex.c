/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:10:26 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/04 19:38:25 by bdenfir          ###   ########.fr       */
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

t_pipex	*init_data(char *file1, char *file2)
{
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	if (!data)
		error_exit("Allocation failed for t_pipex structure");
	data->infile = open(file1, O_RDONLY | O_CREAT, 0644);
	data->outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->infile < 0 || data->outfile < 0)
		error_exit("Error opening files");
	return (data);
}

pid_t	fork_child(t_pipex *data, char **argv, char **envp, int nb_cmd)
{
	pid_t	pid;
	char	*cmd;
	char	**args;

	args = ft_split(argv[1 + nb_cmd], ' ');
	cmd = find_executable(args[0], envp);
	pid = fork();
	if (pid < 0)
		error_exit("Error creating fork/child process");
	if (pid == 0)
	{
		pipe_redirection(nb_cmd, data);
		if (execve(cmd, args, envp) == -1)
			error_exit("command not found");
	}
	free_args(args);
	free(cmd);
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_exit("Invalid argument Usage:./pipex file1 cmd1 cmd2 file2");
	data = init_data(argv[1], argv[argc - 1]);
	create_pipe(data);
	pid1 = fork_child(data, argv, envp, 1);
	pid2 = fork_child(data, argv, envp, 2);
	clean_data(data);
	wait_pid(pid1, pid2);
	free(data);
	return (0);
}
