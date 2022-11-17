#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"

void parseCommand(char *str, command *cmd);
void executeCMD(command *cmd, char *const env[]);

/**
 * main - Launch the shell programm.
 *
 * @ac: Argument count, the number of arguments
 * passed to the program.
 *
 * @av: Argument list, a NULL terminated vector
 * of arguments values.
 *
 * @env: Environment List.
 *
 * Return: Int the exit status.
 */
int main(int ac, char **av, char **env)
{
	pid_t childPid;
	command cmd;
	int status = EXIT_SUCCESS;
	size_t len;
	ssize_t nread;
	char *line = NULL;
	char inputStr[50];
	int i = 0;

	cmd.ppathname = av[0];
	while ((ac > 1 && i == 0) || (ac == 1 && status == 0))
	{
		i++;
		switch (childPid = fork())
		{
			case -1:
				perror("Error");
				status = 1;
				break;
			case 0:
				if (ac > 1)
				{
					_strcpy(inputStr, av[1]);
					parseCommand(inputStr, &cmd);

					executeCMD(&cmd, env);
				}
				else
				{
					printf("#cisfun$ ");
					while ((nread = getline(&line, &len, stdin)) != -1)
					{
						_strcpy(inputStr, line);
						parseCommand(inputStr, &cmd);

						executeCMD(&cmd, env);
						printf("#cisfun$ ");
					}

					if (nread == -1)
						_exit(EXIT_FAILURE);
				}
				_exit(EXIT_SUCCESS);
				break;
			default:
				wait(&status);
				break;
		}
	}

	free(line);
	exit(status);
}

/**
 * parseCommand - Parse a string into a command
 * type.
 *
 * @str: The string to parse.
 * @cmd: A pointer to a command struct.
 */
void parseCommand(char *str, command *cmd)
{
	/* Currently only one command by string */
	cmd->pathname = str;
	cmd->args = malloc(2 * sizeof(cmd->args));
	cmd->args[0] = str;
	cmd->args[1] = NULL;
}

/**
 * executeCMD - Executes a shell command.
 * @cmd: A command pointer.
 * @env: Environment list.
 */
void executeCMD(command *cmd, char *const env[])
{
	if (execve(cmd->pathname, cmd->args, env) == -1)
		perror(cmd->ppathname);
}
