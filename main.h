#ifndef MAIN_H
#define MAIN_H

char *_strcpy(char *dest, char *src);

/**
 * struct Command - Helpers Representing the parameters
 * to execute a program with an exec call.
 * @args: Arguments vector.
 * @pathname: The path of program to execute and the first element of args.
 * @ppathname: The path of the parent program.
 *
 */
struct Command
{
	char **args;
	char *pathname;
	char *ppathname;
};

typedef struct Command command;
#endif /* MAIN_H  */
