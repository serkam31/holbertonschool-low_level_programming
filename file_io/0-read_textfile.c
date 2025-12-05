#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: the actual number of letters it could read and print
 *         0 if the file cannot be opened or read, or if filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, r, w;
	char *text;

	if (filename == NULL || letters == 0)
		return (0);

	text = malloc(letters + 1);
	if (text == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(text);
		return (0);
	}

	r = read(fd, text, letters);
	if (r == -1)
	{
		free(text);
		close(fd);
		return (0);
	}

	w = write(STDOUT_FILENO, text, r);

	free(text);
	close(fd);

	if (w == -1 || w != r)
		return (0);

	return (w);
}
