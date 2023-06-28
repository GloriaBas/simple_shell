#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3

/* for convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2
/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE       ".simple_shell_history"
#define HIST_MAX        4096

extern char **environ;
/**
 * * struct liststr - Represents singly linked list
 * * @num: It is the number field
 * * @str: It is a string
 * * @next: Used to point to the next node
 */
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t;

/**
 * *struct passinfo - Should contain pseudo-arguements that will be passed
 * *into a function to make uniform prototype for function pointer struct
 * *@arg: Defines a string generated from getline containing arguements
 * *@argv: Represnts an array of strings generated from arg
 * *@path: Represents a string path for the current command
 * *@argc: Represents the argument count
 * *@line_count: Stands for the error count
 * *@err_num: Represnts the error code for exit()s
 * *@linecount_flag: Should count this line of input when used
 * *@fname: Represents the program filename
 * *@env: Represents the linked list local copy of environ
 * *@environ: Represents the custom modified copy of environ from LL env
 * *@history: It is the history node
 * *@alias: It is the alias node
 * *@env_changed: Should be on if environ was changed
 * *@status: It is the return status of the last exec'd command
 * *@cmd_buf: aIt is ddress of pointer to cmd_buf, on if chaining
 * *@cmd_buf_type: CMD_type ||, &&, ;
 * *@readfd: Represents the fd from which to read line input
 * *@histcount: Represents the history line number count
 */
typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
int cmd_buf_type; /* CMD_type ||, &&, ; */
int readfd;
int histcount;
} info_t;

#define INFO_INIT \

{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL,
NULL, 0, 0, NULL, \ 0, 0, 0}
/**
 * *struct builtin - Should contain a builtin string and related function
 * *@type: Represents the builtin command flag
 * *@func: Represents the function
 */
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;


/* globe_hsh(sh).c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* globe_pass.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* 01_globe.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* globe_str.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* globe_01_str.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
/* statex.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* globe_split_strwtow.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* globe_resize.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* globe_mem.c */
int bfree(void **);

/* convstr.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* 02_globe.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* exitsh.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* exitsh1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* statget.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* globe_info.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* curenv.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* globe_getenv_flie.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* globe_recall.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* globe_pre.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* globe_01_pre.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* globe_chbuf.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif

