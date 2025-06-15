#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int error(char *str)
{
	while (*str)
		write(2, str++, 1);
	return 1;
}

int cd(char **argv, int i)
{
	if (i != 2)
		error("error: cd: bad arguments\n");
	if (chdir(argv[1]) == -1)
		error("");
	return (0);
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		error("error: fatal\n");
}

int execute(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (has_pipe && pipe(fd) == -1)
        return error("error: fatal\n");

    int pid = fork();
    if (!pid) 
    {
        argv[i] = 0;
        set_pipe(has_pipe, fd, 1);
        execve(*argv, argv, envp);
        return error("error: cannot execute "), error(*argv), error("\n");
    }
    waitpid(pid, &status, 0);
   	set_pipe(has_pipe, fd, 0);
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int i = 0;
	int status = 0;

	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			status = cd(argv, i);
		else if (i)
			status = execute(argv, envp, i);
	}
	return (status);
}