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

	if (isatty(0) == 0)
	{
		non_inter();
		return (0);
	}
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		bytes = read(STDIN_FILENO, buf, 99);
		if (bytes == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		buf[bytes] = '\0';
		argv = splice(buf);
		if (argv == NULL)
			continue;
		path_search(argv);
	}
	return (0);
}
