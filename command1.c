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
 * executeCommand - Executes a given command.
 * @cmd: A pointer to Command struct
 */
void executeCommand(Command_t *cmd)
{
	if (execve(cmd->args[0], cmd->args, environ) == -1)
	{
		perror(cmd->ppathname);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
