#include "main.h"

int main()
{
	int id = 1;
	int i;
	char *argv[] = {"ls", "-l", "/usr/", NULL};

	for (i = 0; i < 1; i++)
	{
		if (id != 0)
			id = fork();
		if (id == 0)
			execve("/bin/ls", argv, NULL);
		wait(NULL);
	}
	printf("done!!\n");
	return (0);
}
