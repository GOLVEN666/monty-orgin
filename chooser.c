#include "monty.h"

/**
* chooser - Select function for needing
* @head: Head of the list
* @token: Parameters for entry
* @line: Number of the line
*
* Return: Void - Nothing
**/
void chooser(stack_t **head, char *token, unsigned int line)
{
instruction_t options[] = {
{"pall", pall},
{"push", push},
{"pint", pint},
{"swap", swap},
{"add", add},
{"nop", nop},
{"pop", pop},
{"sub", sub},
{"mul", mul},
{"div", _div},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};

int i = 0;

while (i < 11)
{
if (strcmp(options[i].opcode, token) == 0)
{
options[i].f(head, line);
return;
}
i++;
}
if (token[0] != '#')
{
fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
exit(EXIT_FAILURE);
}
}
