#ifndef COMMAND_H
#define COMMAND_H

#include <stdlib.h>

/**
 * struct Command_s - Helpers Representing the parameters
 *                  to execute a program with an exec call.
 *
 * @args: Arguments vector.
 * @name: The name of program to execute and the first element of args.
 * @ppathname: The parent program path name.
 * @args_count: The number of arguments set.
 * @args_size: The max number of arguments that can set.
 */
struct Command_s
{
	char **args;
	char *name;
	char *ppathname;
	size_t args_count;
	size_t args_size;
};
typedef struct Command_s Command_t;


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
int parseCommandLine(char *line, Command_t *cmd);

/**
 * parseCommand - Parses command arguments from the arguments
 *                variables of the main funtion.
 * @av: A pointer to arguments variables.
 * @cmd: A poitner to a Command struct.
 */
void parseCommand(char **av, Command_t *cmd);


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
char isExecutable(char *commandName, char filePath[]);


/**
 * executeCommand - Executes a given command.
 *
 * @cmd: A double pointer to a Command_t struct.
 */
void executeCommand(Command_t *cmd);


/**
 * initializeArgs - Allocates memory for the command arguments.
 * @cmd: A pointer to Command_t struct.
 */
void initializeArgs(Command_t *cmd);


/**
 * extendArgs - Increase memory available in the args
 *              member of cmd, by using realloc.
 * @cmd: A pointer to Command_t struct.
 */
void extendArgs(Command_t *cmd);


extern char **environ;
#endif /* COMMAND_H  */
