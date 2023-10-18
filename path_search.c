#include "main.h"

int execute(char *cmd, char **av)
{
	struct stat st;
	int id = getpid();

	if (stat(cmd, &st) == 0)
	{
		fork();
		if (id == getppid())
		{
			execve(cmd, av, environ);
			exit(98);
		}
		wait(NULL);
		return (0);
	}
	return (1);
}

int path_search(char **str)
{
	struct stat st;
	int i = 0;
	int id;
	char **path = psplice(_getenv("PATH"));
	char cmd[100];

	if (str == NULL)
		return (1);
	if (stat(str[i], &st) == 0)
	{
		id = fork();
		if (id == 0)
			execve(str[i], str, environ);
		wait(NULL);
	}
	else
	{
		while (path[i] != NULL)
		{
			_strcpy(cmd, path[i]);
			_strcat(cmd, "/");
			_strcat(cmd, str[0]);
			if (execute(cmd, str) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}
