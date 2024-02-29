#include <stdio.h>
#include <string.h>
#include "string.h"
#include "getenv.h"


/**
 * _getenv - Return the environment variable 'name'
 *           if found.
 *
 * @name: The name of variable to get.
 *
 * Return: A pointer to the value of the variable name
 *         or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i;
	char key[50], *_key;

	_key = key;
	_key = _stpcpy(_key, name);
	_key = _stpcpy(_key, "=");
	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp(key, environ[i], _strlen(key)) == 0)
			return (strtok(environ[i], key));
		i++;
	}

	return (NULL);
}
