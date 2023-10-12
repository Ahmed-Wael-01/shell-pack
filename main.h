#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char **splice(char *str);
int word_len(char *str);
int word_cnt(char *str);

#endif
