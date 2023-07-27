#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
extern int errno;

void execution(char **argv, char *act);
int **token(char *str, char *program, int count);
void execmd(char **argv, char *program, int count);
char *get_loc(char *cmd);
char *str_cat(char *dest, char *src);
int str_len(char *str);
char *str_cpy(char *dest, char *src);
char *str_dup(char *str);

#endif
