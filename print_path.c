#include "main.h"

int main()
{
	int i;
	char **path = psplice(_getenv("PATH"));

	for (i = 0; path[i] != NULL; i++)
		printf("%s\n", path[i]);
	return (0);
}
