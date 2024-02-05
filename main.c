#include "monty.h"

/**
 * main - Main function
 * @ac: Arguments line
 * @av: Arguments vector
 * Return: Default return
 **/

int main(int ac, char *av[])
{
char *arguments, *lineptr = NULL;
unsigned int line = 0;
ssize_t read_file;
stack_t *head = NULL;
FILE *fl;
size_t bufsize;

if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fl = fopen(av[1], "r");
if (!fl)
{
fprintf(stderr, "Error: Can't open file %s\n", av[1]);
exit(EXIT_FAILURE);
}

while ((read_file = _getline(&lineptr, &bufsize, fl)) != -1)
{
arguments = strtok(lineptr, LIMITER);
line++;
if (arguments)
chooser(&head, arguments, line);

else if (!arguments)
continue;

}
if (lineptr)
free(lineptr);
freeer(&head);
fclose(fl);
exit(EXIT_SUCCESS);
}
