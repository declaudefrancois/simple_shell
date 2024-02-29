#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "shell.h"
#include "string.h"
#include "_putchar.h"


/**
 * run - Run the shell in non-interactive mode.
 *       Execute one command and exit.
 *
 * @argv: The argument vector of the shell program.
 */
void run(char **argv)
{
	Command_t cmd;
	char cmdPath[50];
	pid_t pid;
	int status;

	cmd.ppathname = argv[0];
	cmd.args = NULL;
	cmd.args_size = cmd.args_count = 0;

	if (isExecutable(argv[1], cmdPath))
	{
		argv[1] = cmdPath;
		pid = fork();
		if (pid == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			parseCommand(argv, &cmd);
			executeCommand(&cmd);
		}
		else
		{
			wait(&status);
			if (cmd.args != NULL)
				free(cmd.args);

			if (WIFEXITED(status))
				exit(WEXITSTATUS(status));
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
}


/**
 * runInteractive - Run the shell interactivelly.
 * @prog_name: The name of the program running the shell.
 */
void runInteractive(char *prog_name)
{
	Command_t cmd;
	char *commandStr;
	int status, satty_stdin;
	pid_t pid;

	cmd.ppathname = prog_name;
	cmd.args = NULL;
	cmd.args_size = cmd.args_count = 0;
	satty_stdin = isatty(STDIN_FILENO);

	while (1)
	{
		commandStr = handlePrompt();
		commandStr = strtok(commandStr, "\n");
		pid = fork();
		if (pid == -1)
		{
			perror(prog_name);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			cmd.args_count = 0;
			parseCommandLine(commandStr, &cmd);
			if (commandStr == NULL)
				exit(satty_stdin ? EXIT_SUCCESS : EXIT_FAILURE);
			executeCommand(&cmd);
		}
		else
		{
			if (!satty_stdin && !commandStr)
				exit(WEXITSTATUS(status));

			waitpid(pid, &status, 0);
			free(commandStr);
			commandStr = NULL;
		}
	}
}


/**
 * handlePrompt - Handles the command value entered in the
 *                prompt.
 * Return: A pointer to the line got from the prompt
 */
char *handlePrompt(void)
{
	ssize_t read_len;
	size_t line_len;
	char *line;
	char *msg = "#cisfun$ ";
	int satty_stdin;

	satty_stdin = isatty(STDIN_FILENO);
	if (satty_stdin)
	{
		while (*msg != '\0')
			_putchar(*msg++);
	}

	line = NULL;
	read_len = line_len = 0;

	while ((read_len = getline(&line, &line_len, stdin)) != -1)
		return (line);

	if (read_len == -1 && satty_stdin)
		perror("getline");

	return (NULL);
}
