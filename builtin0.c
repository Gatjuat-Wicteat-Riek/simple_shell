#include "shell.h"

/**
 * _myhistory - this displays the history of the file and all
 * the componets.
 * @info: this is the Structure containing the aruments to pass
 * to the element.
 *  Return: On sucess  0 is always returned.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This will set alias to string
 * present.
 * @info: this is the parameter struct to be checked.
 * @str: This is the string alias in the files.
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *ptrr, chc;
	int retu;

	ptrr = _strchr(str, '=');
	if (!ptrr)
		return (1);
	chc = *ptrr;
	*ptrr = 0;
	retu = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ptrr = chc;
	return (retu);
}

/**
 * set_alias - This will set alias to string present.
 * @info: This is the parameter struct
 * @str: this is the string to be aliased
 * Return: 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *ptrr;

	ptrr = _strchr(str, '=');
	if (!ptrr)
		return (1);
	if (!*++ptrr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this will prints an alias of the string
 * @node: this is the alias node
 * Return:  0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *ptrr = NULL, *aa = NULL;

	if (node)
	{
		ptrr = _strchr(node->str, '=');
		for (aa = node->str; aa <= ptrr; aa++)
		_putchar(*aa);
		_putchar('\'');
		_puts(ptrr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - this will mimics the alias builtin
 * fuctions in tyhe proccess.
 * @info: this is the Structure containing potential
 * arguments to return the protype of the function.
 *  Return: On succes  0 is always returned to the console.
 */
int _myalias(info_t *info)
{
	int kk = 0;
	char *ptrr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;

		do {
			print_alias(node);
			node = node->next;
		} while (node);
		return (0);
	}
	for (kk = 1; info->argv[kk]; kk++)
	{
		ptrr = _strchr(info->argv[kk], '=');
		if (ptrr)
			set_alias(info, info->argv[kk]);
		else
			print_alias(node_starts_with(info->alias, info->argv[kk], '='));
	}

	return (0);
}
