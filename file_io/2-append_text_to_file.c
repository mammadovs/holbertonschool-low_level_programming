#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written = 0, len = 0;

	if (filename == NULL)
		return (-1);

	/* Open file in append mode */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content is NULL, just return success */
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	/* Calculate string length */
	while (text_content[len])
		len++;

	/* Write to file */
	bytes_written = write(fd, text_content, len);
	if (bytes_written == -1 || bytes_written != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
