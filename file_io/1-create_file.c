#include "main.h"

/**
 * create_file - creates a file and writes text_content to it
 * @filename: name of the file to create
 * @text_content: string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written = 0;
	size_t length = 0;

	if (!filename)
		return (-1);

	/* Open with create, write-only, truncate */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		return (-1);

	/* Write if we have content */
	if (text_content)
	{
		length = strlen(text_content);
		if (length > 0)
		{
			bytes_written = write(fd, text_content, length);
			if (bytes_written < 0 || (size_t)bytes_written != length)
			{
				close(fd);
				return (-1);
			}
		}
	}

	close(fd);
	return (1);
}
