#include "main.h"

/**
 * check_file - checks if files can be opened.
 * @file_from: file descriptor of the source file.
 * @file_to: file descriptor of the destination file.
 * @argv: vector argument.
 * Return: no return.
 */


void check_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - entry point of the program.
 * @argc: number of arguments.
 * @argv: vector arguments.
 * Return: Always 0(success).
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, error_close;
	ssize_t no_chars, n_write;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	check_file(file_from, file_to, argv);

	no_chars = 1024;

	while (no_chars == 1024)
	{
		no_chars = read(file_from, buffer, 1024);
		if (no_chars == -1)
			check_file(-1, 0, argv);
		n_write = write(file_to, buffer, no_chars);
		if (n_write == -1)
			check_file(0, -1, argv);
	}

	error_close = close(file_from);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	error_close = close(file_to);
	if (error_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
