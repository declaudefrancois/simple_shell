#ifndef STRING_H
#define STRING_H

/**
 * _strcpy - Copies the string src (source) in dest (destination).
 *           And returns the resulting string.
 *
 * @dest: The destination.
 * @src: The source to copy from.
 *
 * Return: A pointer to the resulting string.
 */
char *_strcpy(char *dest, char *src);

/**
 * _stpcpy - Copies the string pointed to by src
 *           to the array pointed to by dest.
 * @dest: A pointer to the destination.
 * @src: A pointer to the source string.
 *
 * Return: a pointer to the end of the
 *         string dest.
 */
char *_stpcpy(char *dest, const char *src);

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
int _strncmp(const char *s1, const char *s2, size_t n);


/**
 * _strlen - Returns the lenght of the string
 *           s.
 * @s: The string to get the length for.
 * Return: size_t, the length of s.
 */
size_t _strlen(const char *s);


/**
 * _puts - writes the string s and a trailing newline to stdout.
 * @str: The strign to write.
 */
void _puts(const char *str);

#endif
