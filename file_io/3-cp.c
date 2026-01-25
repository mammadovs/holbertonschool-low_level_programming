#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - prints error and exits
 * @fd: file descriptor for close errors
 * @filename: filename for read/write errors
 * @error_type: 1=read, 2=write, 3=close, 4=usage
 * @exit_code: exit code to use
 * @close_fd1: fd to close before exit (or -1)
 * @close_fd2: fd to close before exit (or -1)
 */
void print_error_and_exit(int fd, char *filename,
			  int error_type, int exit_code,
			  int close_fd1, int close_fd2)
{
	if (close_fd1 != -1)
		close(close_fd1);
	if (close_fd2 != -1)
		close(close_fd2);

	if (error_type == 1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	else if (error_type == 2)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	else if (error_type == 3)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	else if (error_type == 4)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");

	exit(exit_code);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, various error codes on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];
	mode_t perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		print_error_and_exit(0, NULL, 4, 97, -1, -1);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit(0, argv[1], 1, 98, -1, -1);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, perms);
	if (fd_to == -1)
		print_error_and_exit(0, argv[2], 2, 99, fd_from, -1);

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			print_error_and_exit(0, argv[2], 2, 99, fd_from, fd_to);
	}

	if (bytes_read == -1)
		print_error_and_exit(0, argv[1], 1, 98, fd_from, fd_to);

	if (close(fd_from) == -1)
		print_error_and_exit(fd_from, NULL, 3, 100, -1, -1);

	if (close(fd_to) == -1)
		print_error_and_exit(fd_to, NULL, 3, 100, -1, -1);

	return (0);
}
