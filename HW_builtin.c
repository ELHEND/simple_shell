#include "shell.h"

/**
 * * HW_exit - exits the shell.
 * * @info: Structure containing arguments.
 * *
 * * Return: (0) if info.argv[0] != "exit"
 */
int HW_exit(info_t *info)
{
	int excheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		excheck = HW_erratoi(info->argv[1]);
		if (excheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			HW_eputs(info->argv[1]);
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
 * * HW_cd - changes the current directory of the process
 * * @info: Structure containing arguments.
 * *
 * * Return: Always 0.
 */
int HW_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chd_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)

			chd_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chd_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');

		chd_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chd_ret = chdir(info->argv[1]);
	if (chd_ret == -1)
	{
		print_error(info, "can't cd to ");
		HW_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * * HW_help - changes the current directory.
 * * @info: Structure containing arguments.
 *  *
 *  * Return: Always 0
 */
int HW_help(info_t *info)
{
	char **arg_ar;

	arg_ar = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(arg_ar);
	return (0);
}
