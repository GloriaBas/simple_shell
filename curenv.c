#include "shell.h"
/**
 * * _myenv - Should print the current environment
 * * @info: Represents the structure containing potential arguments
 * * to be used to maintain constant function prototype
 * * Return: Always 0
 */
int _goenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * * _getenv - Should get the value of an environ variable
 * * @info: Represents the structure containing potential arguments
 * * to be used to maintain constant function prototype
 * * @name: Stands for the env var name
 * * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *p;
while (node)
{
p = starts_with(node->str, name);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
 * * _gosetenv - Should commence a new environment variable
 * *  or modify an existing one
 * * @info: Represents the structure containing potential arguments
 * * that will be used to maintain constant function prototype
 * *  Return: Always 0
 */
int _gosetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * * _gounsetenv - Should remove an environment variable
 * * @info: Represents the structure containing potential arguments
 * * used to maintain constant function prototype
 * *  Return: Always 0
 */
int _gounsetenv(info_t *info)
{
int q;
if (info->argc == 1)
{
_eputs("Very few arguements.\n");
return (1);
}
for (q = 1; q <= info->argc; q++)
_unsetenv(info, info->argv[q]);
return (0);
}

/**
 * * populate_env_list - Should populate env linked list
 * * @info: Represents the structure containing potential arguments
 * * that is used to maintain constant function prototype
 * * Return: Always 0
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t q;
for (q = 0; environ[q]; q++)
add_node_end(&node, environ[q], 0);
info->env = node;
return (0);
}
