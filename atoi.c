#include "shell.h"

/**
 * interactive - this will returns true if shell is interactive mode
 * or will return false
 * @info: This is the struct address to
 * be returned
 * Return: in succes 1 returned and 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - This will check if character is a delimeter
 * or it is not a delimantor.
 * @c: This is the charcter to be  checked in the program.
 * @delim: This is the delimeter string to
 * be returned
 * Return: On sucess, 1 is returned and -1 otherwise.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha -this will check for alphabetic characters
 * passed in the codes.
 * @c: This is the character to input to be passed.
 * Return: on sucess 1 is returned and 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - This is a converter of the string to an integer
 * given and passed in the program.
 * @s: this is the string to be converted by the program.
 * Return: on sucess 0 is when no number is found in the
 * and 1 otherwise.
 */

int _atoi(char *s)
{
	int kk, signn = 1, flagg = 0, out_put;
	unsigned int results = 0;

	for (kk = 0; s[kk] != '\0' && flagg != 2; kk++)
	{
		if (s[kk] == '-')
			signn *= -1;

		if (s[kk] >= '0' && s[kk] <= '9')
		{
			flagg = 1;
			results *= 10;
			results += (s[kk] - '0');
		}
		else if (flagg == 1)
			flagg = 2;
	}

	if (signn == -1)
		out_put = -results;
	else
		out_put = results;

	return (out_put);
}
