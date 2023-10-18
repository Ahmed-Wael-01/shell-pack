#include "main.h"

int main()
{
	char *str = "/bin/ls\n/bin/ls";
	char **new;
	char **old;
	int i;

	old = line_breaker(str);
	for (i = 0; old[i] != NULL; i++)
	{
		printf("%s\n", old[i]);
	}
	/*execve(new[0], new, NULL);
	printf("fail!");*/
	return (0);
}
