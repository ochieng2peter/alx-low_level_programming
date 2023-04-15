#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * printHex - prints hexadecimal values
 * @ptr: pointer to buffer
 * @size: size of buffer
 * Return: void
 */
void printHex(char *ptr, int size)
{
	int i; /* Declare variable before the loop*/

	for (i = 0; i < size; i++) /* Move variable declaration before the loop*/
	{
		printf("%02x ", (unsigned char)ptr[i]);
	}
	printf("\n");
}

/**
 * printString - prints string values
 * @ptr: pointer to buffer
 * @size: size of buffer
 * Return: void
 */
void printString(char *ptr, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (ptr[i] == 0)
		{
			break;
		}
		printf("%c", ptr[i]);
	}
	printf("\n");
}

/**
 * printElfInfo - prints information about the ELF file
 * @fileDescriptor: file descriptor of the ELF file
 * Return: void
 */
void printElfInfo(int fileDescriptor)
{
	char buffer[128];

	/* Read the ELF header into buffer */
	int bytesRead = read(fileDescriptor, buffer, sizeof(buffer));

	if (bytesRead < 0)
	{
		perror("Error reading file");
		exit(98);
	}
	if (bytesRead < 4)
	{
		fprintf(stderr, "Error: File is too small to be an ELF file\n");
		exit(98);
	}

	if (buffer[0] != 0x7f || buffer[1] != 'E' ||
		buffer[2] != 'L' || buffer[3] != 'F')
	{
		fprintf(stderr, "Error: File is not an ELF file\n");
		exit(98);
	}

	printf("Magic: ");
	printHex(buffer, 16);
	printf("Class: %s\n", (buffer[4] == 1) ? "ELF32" : "ELF64");
	printf("Data: %s\n", (buffer[5] == 1) ? "Little Endian" : "Big Endian");
	printf("Version: %d\n", (int)buffer[6]);
	printf("OS/ABI: %d\n", (int)buffer[7]);
	printf("ABI Version: %d\n", (int)buffer[8]);
	printf("Type: %d\n", *((short *)&buffer[16]));
	printf("Entry point address: 0x%02x%02x%02x%02x\n",
			(unsigned char)buffer[27],
			(unsigned char)buffer[26],
			(unsigned char)buffer[25],
			(unsigned char)buffer[24]);
}

/**
 * main - entry point of the program
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 * Return: exit status
 */

int main(int argc, char *argv[])
{
	int fileDescriptor;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(98);
	}
	fileDescriptor = open(argv[1], O_RDONLY);

	if (fileDescriptor < 0)
	{
		perror("Error opening file");
		exit(98);
	}
	printElfInfo(fileDescriptor);
	close(fileDescriptor);
	return (0);
}
