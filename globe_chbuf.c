#include "shell.h"

/**
 *  * is_chain - Should test if current char in buffer is a chain delimeter
 *  * @info: It is the parameter struct
 *  * @buf: It is the char buffer
 *  * @p: It is the address of current position in buf
 *  * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t o = *p;
if (buf[o] == '|' && buf[o + 1] == '|')
{
buf[o = 0;
o++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[o] == '&' && buf[o + 1] == '&')
{
buf[o] = 0;
o++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[o] == ';') /* found end of this command */
{
buf[o] = 0; /* replace semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = o;
return (1);
}

/**
 *  * check_chain - Should check if we should continue
 *  * chaining based on last status
 *  * @info: Stands for the parameter struct
 *  * @buf: Stands for the char buffer
 *  * @p: Stands for the address of current position in buf
 *  * @g: It is the starting position in buf
 *  * @len: Represents the length of buf
 *  * Return:()
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t g, size_t len)
{
size_t o = *p;
if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[g] = 0;
o = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[g] = 0;
o = len;
}
}
*p = o;
}

/**
 *  * replace_alias - Should replace an alias in the tokenized string
 *  * @info: It is the parameter struct
 *  * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
int g;
list_t *node;
char *p;
for (g = 0; g < 10; g++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/**
 *  * replace_vars - Should replace vars in the tokenized string
 *  * @info: It is the parameter struct
 *  * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
int g = 0;
list_t *node;
for (g = 0; info->argv[g]; g++)
{
if (info->argv[g][0] != '$' || !info->argv[g][1])
continue;
if (!_strcmp(info->argv[g], "$?"))
{
replace_string(&(info->argv[g]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[g], "$$"))
{
replace_string(&(info->argv[g]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
replace_string(&(info->argv[g]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[g], _strdup(""));
}
return (0);
}

/**
 *  * replace_string - Should replace string
 *  * @old: It is the address of old string
 *  * @new: It is the new string
 *  * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
