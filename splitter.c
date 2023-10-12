#include "main.h"

/**
 * a word counter
 * to help the splitter
 */

int word_cnt(char *str)
{
	int counter = 0;
	int i = 0;

	if (str[i] != ' ')
		counter++;
	i++;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i - 1] == ' ')
			counter++;
		i++;
	}
	return (counter);
}

/**
 * it gives the length of the word
 * to help the splitter
 */

int word_len(char *str)
{
	 int len = 0;

        while (str[len] != '\0' && str[len] != ' ' && str[len] != '\n')
                len++;
        return (len);
}

/**
 * it gives back an array of words
 * AKA two dimentional array
 * kinda like a fruit slicer
 */

char **splice(char *str)
{
	int i, j, wn = 0;
	char **vessel;
	i = word_cnt(str);
	vessel = malloc(sizeof(str) * i + 1);
	for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)
	{
		if (str[i] != ' ')
		{
			j = word_len(&str[i]);
			*(vessel + wn) = malloc(sizeof(char) * j + 1);
			for (j = 0; str[i] != '\0' && str[i] != ' '
				&& str[i] != '\n'; j++)
			{
				*(*(vessel + wn) + j) = str[i];
				i++;
			}
			*(*(vessel + wn) + j) = '\0';
			i--, wn++;
		}
	}
	*(vessel + wn) = NULL;
	return (vessel);

}
