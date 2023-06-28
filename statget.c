#include "shell.h"

/**
 * * input_buf - Should be the buffers chained commands
 * * @info:Represents parameter struct
 * * @buf: Represents address of buffer
 * * @len: Represents the address of len var
 * * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t q = 0;
size_t len_p = 0;
if (!*len) /* if nothing left in the buffer, fill it */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
q = getline(buf, &len_p, stdin);
#else
q = _getline(info, buf, &len_p);
#endif
if (q > 0)
{
if ((*buf)[q - 1] == '\n')
{
(*buf)[q - 1] = '\0'; /* remove trailing newline */
q--;
{
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*len = q;
info->cmd_buf = buf;
}
}
}
return (q);
}

/**
 * * get_input - Should get a line minus the newline
 * * @info: It is the parameter struct
 * * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
static char *buf; /* the ';' command chain buffer */
static size_t g, o, len;
ssize_t q = 0;
char **buf_p = &(info->arg), *p;
_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);
if (q == -1) /* EOF */
return (-1);
if (len)	/* we have commands left in the chain buffer */
{
o = g; /* init new iterator to current buf position */
p = buf + g; /* get pointer for return */
check_chain(info, buf, &o, g, len);
while (o < len) /* iterate to semicolon or end */
{
if (is_chain(info, buf, &j);
break;
o++;
}
g = o + 1; /* increment past nulled ';'' */
if (g >= len) /* reached end of buffer? */
{
g = len = 0; /* reset position and length */
info->cmd_buf_type = CMD_NORM;
}
*buf_p = p; /* pass back pointer to current command position */
return (_strlen(p)); /* return length of current command
*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
return (q); /* return length of buffer from _getline() */
}

/**
 * * read_buf - Should read a buffer
 * * @info: It is the parameter struct
 * * @buf: It is the buffer
 * * @g: It is the size
 * * Return: q
 */
ssize_t read_buf(info_t *info, char *buf, size_t *g)
{
ssize_t q = 0;
if (*g)
return (0);
q = read(info->readfd, buf, READ_BUF_SIZE);
if (q >= 0)
*g = q;
return (q);
}

/**
 * * _getline - Should get the next line of input from STDIN
 * * @info: It is the parameter struct
 * * @ptr: It is the address of pointer to buffer, preallocated or NULL
 * * @length: It is size of preallocated ptr buffer if not NULL
 * * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
size_t w;
ssize_t q = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;
p = *ptr;
if (p && length)
s = *length;
if (g == len)
g = lenr = read_buf(info, buf, &len);
if (q == -1 || (q == 0 && len == 0))
return (-1);
c = _strchr(buf + g, '\n');
w = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, s, s ? s + w : w + 1);
if (!new_p) /* MALLOC FAILURE! */
return (p ? free(p), -1 : -1);
if (s)
_strncat(new_p, buf + g, w - g);
else
_strncpy(new_p, buf + g, w - g + 1);
s += w - g;
g = w;
p = new_p;
if (length)
*length = s;
*ptr = p;
return (s);
}

/**
 * * sigintHandler - Should block ctrl-C
 * * @sig_num: It is the signal number
 * * Return: ()
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
