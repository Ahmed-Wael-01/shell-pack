#include "main.h"

int main()
{
	int id = 1;
	int i;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	for (i = 0; i < 5; i++)
	{
		if (id != 0)
			id = fork();
		if (id == 0)
			execve(argv[0], argv, NULL);
		wait(NULL);
	}
	printf("done!!\n");
	return (0);
}
