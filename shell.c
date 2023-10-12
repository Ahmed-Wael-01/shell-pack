#include "main.h"

/**
 * starting point
 */

int main()
{
	int bytes;
	char buf[100];
	char **argv;
	int id;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		bytes = read(STDIN_FILENO, buf, 100);
		if (bytes == 0)
			break;
		buf[bytes] = '\0';
		argv = splice(buf);
		id = fork();
		if (id == 0)
		{
			execve(argv[0], argv, NULL);
			return (1);
		}
		wait(NULL);
	}
	return (0);
}
