#include "main.h"

int main(int ac, char **av, char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	printf("this is an env value: %s\n", _getenv("PATH"));
	printf("this is an env value: %s\n", _getenv("LANG"));
	printf("this is an env value: %s\n", _getenv("PWD"));
	printf("this is an env value: %s\n", _getenv("missing"));
	return (0);
}
