#include "main.h"

/**
 * custom_create_file - creates a file with perm.
 * @custom_filename: name of file to create
 * @custom_text_content: content to write in the file.
 *
 * Return: 1 if it success. -1 if it fails(e.g if NULL)
 */

int create_file(const char *filename, char *text_content)
{
	int filedes;
	int nlters;
	int rwr;

	if (!filename)
		return (-1);

	filedes = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (filedes == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nlters = 0; text_content[nlters]; nlters++)
		;

	rwr = write(filedes, text_content, nlters);

	if (rwr == -1)
		return (-1);

	close(filedes);

	return (1);
}
