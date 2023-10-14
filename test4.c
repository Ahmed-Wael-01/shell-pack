#include "main.h"

int main(int ac, char **av, char **env)
{
	printf("The env address is: %p\nThe environ address is: %p\n", env, __environ);
	return (0);
}
