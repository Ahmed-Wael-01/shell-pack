#include "main.h"

int main()
{
	char *str = "hi lina how are you\n";
	int i;
	int wc = word_cnt(str);
	char **buf;

	buf = splice(str);
	for (i = 0; buf[i] != NULL; i++)
	{
		printf("%s\n", buf[i]);
	}
	return (0);
}
