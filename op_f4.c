#include "monty.h"

/**
* _getline - Read a line from a file stream and store it in a
* dynamically allocated buffer
* @line: Pointer to a char pointer that will store the read line.
*        The buffer will be allocated inside the function.
* @line_size: Pointer to a size_t variable that stores the size of
* the allocated buffer.
* If the buffer needs to be expanded, this value will be updated accordingly.
* @stream: Pointer to the file stream from which to read the line.
*
* Return: The number of characters read, or -1 if an error occurred.
*/
ssize_t _getline(char **line, size_t *line_size, FILE *stream)
{
int c;
size_t i = 0;
*line_size = 0;

if (!line || !line_size || !stream)
return (-1);

*line = (char *)malloc(sizeof(char));
if (!(*line))
return (-1);

while (((c = fgetc(stream)) != EOF) && (c != '\n'))
{
if (i >= *line_size)
{
*line_size += 16;
*line = (char *)realloc(*line, *line_size * sizeof(char));
if (!(*line))
return (-1);
}

(*line)[i++] = (char)c;
}

(*line)[i] = '\0';

if (c == EOF && i == 0)
return (-1);

return ((ssize_t)i);
}

/**
 * freeer - Frees memory in stack
 * @head: Head of the list
 * Return: Void - Nothing
 **/

void freeer(stack_t **head)
{
stack_t *tmp;
stack_t *head_list;

head_list = *head;

while (head_list)
{
tmp = head_list;
head_list = head_list->next;
free(tmp);
}
}
