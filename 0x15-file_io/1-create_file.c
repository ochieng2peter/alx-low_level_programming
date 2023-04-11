#include "main.h"

/**
 * custom_create_file - creates a file with perm.
 * @custom_filename: name of file to create
 * @custom_text_content: content to write in the file.
 *
 * Return: 1 if it success. -1 if it fails(e.g if NULL)
 */

int custom_create_file(const char *custom_filename, char *custom_text_content)
{
	int file_descriptor;
	int num_letters;
	int result;

	if (!custom_filename)
	{
		return (-1);
	}
	file_descriptor = open(custom_filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_descriptor == -1)
	{
		return (-1);
	}

	if (!custom_text_content)
		custom_text_content = "";

	for (num_letters = 0; custom_text_content[num_letters]; num_letters++)
		;

	result = write(file_descriptor, custom_text_content, num_letters);

	if (result == -1)
	{
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
