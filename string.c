#include <stdlib.h>
#include "string.h"
#include "_putchar.h"


/**
 * _stpcpy - Copies the string pointed to by src
 *           to the array pointed to by dest.
 * @dest: A pointer to the destination.
 * @src: A pointer to the source string.
 *
 * Return: a pointer to the end of the
 *         string dest.
 */
char *_stpcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (&(dest[i]));
}


/**
 * _strncmp - Comapares the n first char of the strings
 *            s1 and s2.
 *
 * @s1: The first string.
 * @s2: The second string.
 * @n: The max length to compare.
 *
 * Return: 0 if the first n char of s1 matches s2
 *         or less than 0 if s1 < s2
 *         or more than 0 if s1 > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (_strlen(s1) - _strlen(s2));
		i++;
	}
	return (0);
}

/**
 * _strlen - Returns the lenght of the string
 *           s.
 * @s: The string to get the length for.
 * Return: size_t, the length of s.
 */
size_t _strlen(const char *s)
{
	int size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}


/**
 * _strcpy - Copies the string src (source) in dest (destination).
 *           And returns the resulting string.
 *
 * @dest: The destination.
 * @src: The source to copy from.
 *
 * Return: A pointer to the resulting string.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\n' && (dest[i] = src[i]) != '\0')
		i++;
	return (dest);
}


/**
 * _puts - writes the string s and a trailing newline to stdout.
 * @str: The strign to write.
 */
void _puts(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		_putchar(str[i]);
	_putchar('\n');
}
