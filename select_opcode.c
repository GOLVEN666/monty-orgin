#include "monty.h"

/**
 * find_opcode - finds the right function to execute based on the opcode
 *
 * @code: the function's opcode
 *
 * Return: pointer to the selected function
 */
void (*find_opcode(char *code))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t stack_functions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _divide},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}};

	for (i = 0; stack_functions[i].opcode; i++)
	{
		if (strcmp(stack_functions[i].opcode, code) == 0)
		{
			return stack_functions[i].f;
		}
	}

	return NULL; // Return NULL if opcode is not found
}
