#include "shell.h"

/**
 * _myexit - this is an exits to the shell
 * @info: this is the Structure containing
 * the potential arguments to be used later in the
 * program.
 * Return: This will exit with a given exit status
 * when the system is done and leave the shell.
 */
int _myexit(info_t *info)
{
	int exit_checker;

	if (info->argv[1])
	{
		exit_checker = _erratoi(info->argv[1]);
		if (exit_checker == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd -this will  change the current directory of the
 * shell and take u to new directory.
 * @info: Thos is the Structure containing potential arguments
 * which will be maitain in the shell.
 * Return: On sucess, zer or 0 is returned.
 */
int _mycd(info_t *info)
{
	char *ss, *direct, buffer[1024];
	int chdir_dir;

	ss = getcwd(buffer, 1024);
	if (!ss)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		direct = _getenv(info, "HOME=");
		if (!direct)
			chdir_dir =
				chdir((direct = _getenv(info, "PWD=")) ? direct : "/");
		else
			chdir_dir = chdir(direct);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(ss);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_dir =
		chdir((direct = _getenv(info, "OLDPWD=")) ? direct : "/");
	}
	else
		chdir_dir = chdir(info->argv[1]);
	if (chdir_dir == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - this changes the current working directory
 * of th shell and direct to another directory.
 * @info: This is the Structure containing potential arguments
 * in the process.
 * Return: on sucess 0 is always returned.
 */
int _myhelp(info_t *info)
{
	char **ar_arry;

	ar_arry = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*ar_arry);
	return (0);
}
