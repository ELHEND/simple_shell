#include "shell.h"
/**
 *  * input_BUF- chained commands
 *  * @info: parameter struct.
 *  * @BUF: address of buffer.
 *  * @len: address of len var.
 *  *
 *  * Return: bytes.
 */
ssize_t input_BUF(info_t *info, char **BUF, size_t *len)
{
ssize_t R = 0;
size_t len_P = 0;

if (!len)

{
/* bfree((void *)info->cmd_BUF);*/
free(*BUF);
*BUF = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
R = getline(BUF, &len_P, stdin);
#else
R = _getline(info, BUF, &len_P);
#endif
if (R > 0)
{
if ((*BUF)[R - 1] == '\n')
{
(BUF)[R - 1] = '\0';
R--;
}
info->linecount_flag = 1;
remove_comments(*BUF);
build_history_list(info, *BUF, info->histcount++);
/* if (_strchr(*BUF, ';')) is this a command chain? */
{
*len = R;
info->cmd_BUF = BUF;
}
}
}
return (R);
}

/**
 *  * get_input - gets a line.
 *  * @info: parameter struct.
 *  *
 *  * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char BUF; /*the ';' command chain buffer */
	static size_t m, n, len;
	ssize_t R = 0;
	char **BUF_P = &(info->arg), *P;

	_putchar(BUF_FLUSH);
	R = input_BUF(info, &BUF, &len);
	if (R == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		n = m; /* init new iterator to current buf position */
		P = BUF + m; /* get pointer for return */

		check_chain(info, BUF, &n, n, len);
		while (n < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, BUF, &n))
				break;
			n++;
		}

		m = n + 1; /* increment past nulled ';'' */
		if (m >= len) /* reached end of buffer? */
		{
			m = len = 0; /* reset position and length */
			info->cmd_BUF_type = CMD_NORM;
		}

		BUF_P = P;
		return (_strlen(P));
	}

	BUF_P = BUF;
	return (R);
}

/**
 *  * read_BUF - reads a buffer
 *  * @info: parameter struct
 *  * @BUF: buffer
 *  * @m: size
 *  *
 *  * Return: R
 */
ssize_t read_BUF(info_t *info, char *BUF, size_t *m)
{
	ssize_t R = 0;

	if (*m)
		return (0);
	R = read(info->readfd, BUF, READ_BUF_SIZE);
	if (R >= 0)
		*m = R;
	return (R);
}

/**
 *  * _getline - gets the line of input from STDIN
 *  * @info: parameter struct.
 *  * @ptr: address of pointer to buffer.
 *  * @length: size of preallocated ptr buffer if not NULL.
 *  *
 *  * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char BUF[READ_BUF_SIZE];
	static size_t m, len;
	size_t e;
	ssize_t R = 0, s = 0;
	char *P = NULL, *NEW_p = NULL, *c;

	P = *ptr;
	if (P && length)
		s = *length;
	if (m == len)
		m = len = 0;

	R = read_BUF(info, BUF, &len);
	if (R == -1 || (R == 0 && len == 0))
		return (-1);

	c = _strchr(BUF + m, '\n');
	e = c ? 1 + (unsigned int)(c - BUF) : len;
	new_P = _realloc(P, s, s ? s + e : e + 1);
	if (!NEW_P) /* MALLOC FAILURE! */
		return (P ? free(P), -1 : -1);

	if (s)
		_strncat(NEW_P, BUF + m, e - m);
	else
		_strncpy(NEW_P, BUF + m, e - m + 1);

	s += e - m;
	m = e;
	P = NEW_P;

	if (length)
		*length = s;
	*ptr = P;
	return (s);
}
/**
 *  * sigintHandler - blocks the ctrl-C.
 *  * @sig_num: the signal number
 *  *
 *  * Return: nothing
 */
void sigintHandler(_attribute_((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
