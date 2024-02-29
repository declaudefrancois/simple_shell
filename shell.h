#ifndef MAIN_H
#define MAIN_H


/**
 * handlePrompt - Handles the command value entered in the
 *                prompt.
 * Return: A pointer to the line got from the prompt.
 */
char *handlePrompt(void);


/**
 * run - Run the shell in non-interactive mode.
 *       Execute one command and exit.
 *
 * @argv: The argument vector of the shell program.
 */
void run(char **argv);


/**
 * runInteractive - Run the shell interactivelly.
 * @prog_name: The name of the program running the shell.
 */
void runInteractive(char *prog_name);


/**
 * handlePrompt - Handles the command value entered in the
 *                prompt.
 * Return: A pointer to the line got from the prompt
 */
char *handlePrompt(void);

#endif
