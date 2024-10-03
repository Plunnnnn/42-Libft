#include "pipex.h"

#include <sys/wait.h>


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
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

t_pipex	*init_data(char *file1, char *file2)
{
	t_pipex	*data;
	
	data = malloc(sizeof(t_pipex));
	if (!data)
		error_exit("Allocatio faile for t-pipex structure");
	
	data->pipe_fd[0] = open(file1, O_RDWR);
	data->pipe_fd[1] = open(file2, O_RDWR);
	return (data);
	// if (data->pipe_fd[0] < 1 || data->pipe_fd[1] < 1)
	// {
	// 	perror("error opening specified file");
	// 	exit(EXIT_FAILURE);
	// }
	// if(dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
	// {
	// 	perror("error redirection to STDIN_FILENO");
	// 	exit(EXIT_FAILURE);
	// }
	// if(dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
	// {
	// 	perror("error redirection to STDOUT_FILENO");
	// 	exit(EXIT_FAILURE);
	// }
}

void	error_exit(char *str)
{
	
	perror(str);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex *data;
	pid_t pid1;
	pid_t	pid2;

	if (argc != 5)
		error_exit("Invalid argument count. Usage: ./pipex file1 cmd1 cmd2 file2");
	data = init_data(argv[1], argv[argc-1]);
	create_pipe(data);
	pid1 = fork_child(data, data->pipe_fd, argv, envp);
	pid2 = fork_child(data, data->pipe_fd, argv, envp);
	printf("%d, %d", pid1, pid2);
	//close_pipes_and_files(&data, pipe_fd);
	//wait_for_children(pid1, pid2);

	return (0);
	
}

pid_t	fork_child(t_pipex *data, int pipe_fd[2], char **argv, char **envp)
{
	pid_t	pid;
	char	*cmd;
	char 	**args;

	pid = fork();
	args = ft_split(argv[1], ' ');
	cmd = find_executable(args[0], envp);
	printf("ICICICICI");
	printf("%d, %s, %s", pid, cmd, args[1]);
	if (pid < 1)
		error_exit("error creating fork/child process");
	if(pipe_fd[0] != STDIN_FILENO)
	{
		close(STDIN_FILENO);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
	if (pipe_fd[1] != STDOUT_FILENO)
	{
		close(STDOUT_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	
	if(execve(cmd, args, envp) == -1)
		error_exit("failed to execute command");
	printf("%d", data->pipe_fd[0]);
	return(pid);
	
}

void create_pipe(t_pipex *data)
{
	if (pipe(data->pipe_fd) == -1)
		error_exit("failed toi create pipe");
}

