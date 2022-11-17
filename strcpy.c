/**
 * _strcpy - copy a string
 * @dest: the destination
 * @src: the string to be copied
 *
 * Return: a pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\n' && (dest[i] = src[i]) != '\0')
		i++;
	return (dest);
}
