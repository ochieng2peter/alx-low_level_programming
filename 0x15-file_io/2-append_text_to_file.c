#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: Name of the file.
 * @text_content: added text content.
 *
 * Return: 1 on success. -1 if the file does not exist
 *	or on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int filedes;
	int wr;
	int nlters;

	if (!filename)
		return (-1);

	filedes = open(filename, O_WRONLY | O_APPEND);

	if (filedes == -1)
		return (-1);

	if (text_content)
	{
		for (nlters = 0; text_content[nlters]; nlters++)
			;

		wr = write(filedes, text_content, nlters);

		if (wr == -1)
			return (-1);
	}

	close(filedes);

	return (1);
}
