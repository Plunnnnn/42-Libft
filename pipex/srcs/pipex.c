#include "pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	exec_cmd(char *cmd, char **envp)
{
	char **args = NULL;

	args = ft_split(cmd, ' ');
	if (!args)
		error_exit("split error");

	// Try to execute the command
	if (execve(args[0], args, envp) == -1)
		error_exit("execve error");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd1, fd2, pipe_fd[2];
	pid_t	pid1, pid2;

	if (argc != 5)
	{
		fprintf(stderr, "Usage: %s file1 cmd1 cmd2 file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Open file1 for reading
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		error_exit("file1 open error");

	// Open file2 for writing (create or truncate)
	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 < 0)
		error_exit("file2 open error");

	// Create the pipe
	if (pipe(pipe_fd) == -1)
		error_exit("pipe error");

	// Fork the first child to execute cmd1
	pid1 = fork();
	if (pid1 == -1)
		error_exit("fork error");

	if (pid1 == 0) // Child 1 - execute cmd1
	{
		// Redirect stdin to file1
		if (dup2(fd1, STDIN_FILENO) == -1)
			error_exit("dup2 file1 error");
		// Redirect stdout to pipe write-end
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit("dup2 pipe write-end error");

		// Close unused pipe ends and file descriptors
		close(fd1);
		close(fd2);
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		// Execute cmd1
		exec_cmd(argv[2], envp);
	}

	// Fork the second child to execute cmd2
	pid2 = fork();
	if (pid2 == -1)
		error_exit("fork error");

	if (pid2 == 0) // Child 2 - execute cmd2
	{
		// Redirect stdin to pipe read-end
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			error_exit("dup2 pipe read-end error");
		// Redirect stdout to file2
		if (dup2(fd2, STDOUT_FILENO) == -1)
			error_exit("dup2 file2 error");

		// Close unused pipe ends and file descriptors
		close(fd1);
		close(fd2);
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		// Execute cmd2
		exec_cmd(argv[3], envp);
	}

	// Parent process: Close all file descriptors and pipe ends
	close(fd1);
	close(fd2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	// Wait for both children to finish
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return 0;
}