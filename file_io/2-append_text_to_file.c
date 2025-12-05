#include "main.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: Name of the file
 * @text_content: NULL terminated string to add at the end
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;
	size_t length = 0;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Open file for writing (append mode), don't create if doesn't exist */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content is NULL, just check if file exists and is writable */
	if (text_content == NULL)
	{
		close(fd);
		return (1); /* File exists and is writable */
	}

	/* Get length and write */
	length = strlen(text_content);
	bytes_written = write(fd, text_content, length);

	/* Check if write succeeded */
	if (bytes_written == -1 || (size_t)bytes_written != length)
	{
		close(fd);
		return (-1);
	}

	/* Success */
	close(fd);
	return (1);
}
