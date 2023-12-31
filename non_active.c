#include "main.h"

void non_inter(void)
{
	int bytes;
	char buf[6144];
	char **argv;
	char **lines;
	int id;
	int i = 0, j = 0;

	bytes = read(STDIN_FILENO, buf, 6143);
	if (bytes == 0)
		return;
	buf[bytes] = '\0';
	lines = line_breaker(buf);

	while (lines[i] != NULL)
	{
		argv = splice(lines[i]);
		if (argv == NULL)
			return;
		path_search(argv);
		i++;
	}
}
