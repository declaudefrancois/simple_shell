#include "shell.h"

/**
 * main - Simple shell entry point.
 * @ac: int, The program's arguments count.
 * @argv: A pointer to the program's arguments.
 *
 * Return: (0) EXIT_SUCCESS on success or (1)
 *         EXIT_FAILURE on failure.
 */
int main(int ac, char **argv)
{
	if (ac > 1)
		run(argv);
	else
		runInteractive(argv[0]);

	return (0);
}
