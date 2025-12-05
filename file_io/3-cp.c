#include "main.h"

/**
 * error_97 - prints error message and exits
 * Return: error 97
 */
void error_97(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * error_98 - prints error message and exits
 * @file: file name
 * Return: error 98
 */
void error_98(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * error_99 - prints error message and exits
 * @file: file name
 * Return: error 99
 */
void error_99(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * error_100 - prints error message and exits
 * @fdescriptor: file descriptor
 * Return: error 100
 */
void error_100(int fdescriptor)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdescriptor);
	exit(100);
}
/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, r, w;
	char buffer[1024];

	if ((argc != 3))
		error_97();

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_98(argv[1]);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close(file_from);
		error_99(argv[2]);
	}
	while ((r = read(file_from, buffer, 1024)) > 0)
	{
		w = write(file_to, buffer, r);
		if (w != r)
		{
			close(file_from);
			close(file_to);
			error_99(argv[2]);
		}
	}
	if (r == -1)
	{
		close(file_from);
		close(file_to);
		error_98(argv[1]);
	}
	if (close(file_from) == -1)
		error_100(file_from);

	if (close(file_to) == -1)
		error_100(file_to);

	return (0);
}
