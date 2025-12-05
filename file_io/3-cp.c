#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * main - Copies the content of a file to another file
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, various error codes on failure
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close(fd_from);
		exit(99);
	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (bytes_read == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);

	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	return (0);
}
