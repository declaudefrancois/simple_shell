#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include<stddef.h>
#include<sys/stat.h>
#include <wchar.h>
#include <errno.h>

#include "command.h"
#include "string.h"
#include "getenv.h"


/**
 * parseCommand - Parses command arguments from the arguments
 *                variables of the main funtion.
 * @av: A pointer to arguments variables.
 * @cmd: A poitner to a Command struct.
 */
void parseCommand(char **av, Command_t *cmd)
{
	int i;

	if (cmd->args_size == 0)
		initializeArgs(cmd);

	i = 1;
	cmd->args_count = 0;
	while (av[i] != NULL)
	{
		extendArgs(cmd);
		cmd->args[i - 1] = av[i];
		i++;
		cmd->args_count++;
	}

	extendArgs(cmd);
	cmd->args[i] = NULL;
	cmd->args_count += 1;
}


/**
 * parseCommandLine - Takes a string entered as a command
 *                    and parses and validates it in a command
 *                    struct pointer.
 *
 * @line: The command input.
 * @cmd: A pionter to a Command struct.
 *
 * Return: int, -1 if something went wrong otherwise 1;
 */
int parseCommandLine(char *line, Command_t *cmd)
{
	int i;
	char *token, cmdPath[50], tmp[100];

	if (cmd->args_size == 0)
		initializeArgs(cmd);

	token = strtok(_strcpy(tmp, line), " ");
	if (token == NULL)
		return (-1);

	if (isExecutable(token, cmdPath) != 1)
	{
		perror(cmd->ppathname);
		return (-1);
	}

	i = 0;
	cmd->args[i++] = cmdPath;
	cmd->args_count = i;

	/**
	 * Reset the strtok internal pointer.
	 */
	strtok(line, " ");
	while ((token = strtok(NULL, " ")))
	{
		extendArgs(cmd);
		cmd->args[i++] = token;
		cmd->args_count++;
	}

	extendArgs(cmd);
	cmd->args[i] = NULL;
	cmd->args_count += 1;
	return (1);
}


/**
 * initializeArgs - Allocates memory for the command arguments.
 * @cmd: A pointer to Command_t struct.
 */
void initializeArgs(Command_t *cmd)
{
	const int nmemb = 8;

	cmd->args = malloc(nmemb * sizeof(char *));
	if (cmd->args == NULL)
	{
		perror(cmd->ppathname);
		exit(EXIT_FAILURE);
	}
	cmd->args_size = nmemb;
	cmd->args_count = 0;
}


/**
 * extendArgs - If the available memory in the args member is smaller
 *              or equal to the used memory, increases it by using realloc.
 * @cmd: A pointer to Command_t struct.
 */
void extendArgs(Command_t *cmd)
{
	const int nmemb_incr = 4;
	size_t newSize;

	if (cmd->args_count >= cmd->args_size)
	{
		newSize = (cmd->args_size + nmemb_incr) * sizeof(char *);
		/*printf("%ld -> %ld\n",cmd->args_size, newSize);*/
		cmd->args = realloc(cmd->args, newSize);
		if (cmd->args == NULL)
		{
			perror(cmd->ppathname);
			exit(EXIT_FAILURE);
		}
		cmd->args_size += nmemb_incr;
	}
}


/**
 * isExecutable - Tests if a given commandName actually
 *                corresponds to an executable.
 *
 * @commandName: The comamnd name to test against.
 * @filePath: A char array that will contain the absolute path
 *            to the command file.
 *
 * Return: 1 if comamndName is executable otherwise 0.
 */
char isExecutable(char *commandName, char filePath[])
{
	char *path, *dir, *_filePath;
	struct stat st;

	if (stat(commandName, &st) == 0)
	{
		_strcpy(filePath, commandName);
		return (1);
	}

	path = _getenv("PATH");
	if (path != NULL)
	{
		dir = strtok(path, ":");
		while (dir != NULL)
		{
			/**
			 * concatenates `dir/commandName`
			 */
			_filePath = filePath;
			_filePath = _stpcpy(_filePath, dir);
			_filePath = _stpcpy(_filePath, "/");
			_filePath = _stpcpy(_filePath, commandName);
			if (stat(filePath, &st) == 0)
				return (1);

			filePath[0] = '\0';
			dir = strtok(NULL, ":");
		}
	}

	return (0);
}

