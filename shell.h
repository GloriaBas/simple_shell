#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>

/* str_modifiers */
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
int _puts(char *str);
char *read_line(void);



#endif
