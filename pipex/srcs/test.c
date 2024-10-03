#include "pipex.h"
 
int main()
{
	int fd1;
	int fd2;

	// Open file1 for reading
	fd1 = open("file1", O_RDONLY);
	if (fd1 < 0)
	{
		perror("open file1");
		exit(1);
	}

	// Open file2 for writing (O_WRONLY) and create/truncate it
	fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		perror("open file2");
		exit(1);
	}

	if (dup2(fd1, STDIN_FILENO) == -1)
	{
		perror("error dup fd1");
		exit(1);
	}
	if (dup2(fd2, STDOUT_FILENO) == -1)
	{
		perror("error dup fd2");
		exit(1);
	}
	execlp("pwd", "pwd", NULL);
	close(fd1);
	close(fd2);
	return 0;
}