#include "shell.h"

/**
 * is_comms - A function that determines if a file is an executable command
 * @path: path to the file
 * @info: the info struct
 * Return: 1 if true, 0 otherwise
 */

int is_comms(info_t, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * go_path - A function that finds the command in the PATH string
 * @info: the info struct
 * @pathstr: PATH string
 * @command: command to find
 * Return: path of command if found or NULL
 */

char *go_path(info_t *info, char *pathstr, char *command)
{
	int g = 0, current_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(command) > 2) && starts_with(command, "./"))
	{
		if (is_comms(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[g] || pathstr[g] == ':')
		{
			path = dup_chars(pathstr, current_pos, g);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (is_comms(info, path))
				return (path);
			if (!pathstr[g])
				break;
			current_pos = g;
		}
		g++;
	}
	return (NULL);
}

/**
 * dup_chars - A function that duplicates characters
 * @pathstr: PATH string
 * @start: starting index
 * @end: ending index
 * Return: pointer to new buffer
 */

char *dup_chars(char *pathstr, int start, int end)
{
	static char buffer[1024];
	int g = 0, j = 0;

	for (j = 0, g = start; g < stop; g++)
		if (pathstr[g] != ':')
			buffer[j++] = pathstr[g];
	buffer[j] = 0;
	return (buf);
