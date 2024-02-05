#include "monty.h"


/**
 * main - monty interpreter
 *
 * @argc: number of arguments
 * @argv: passed arguments
 *
 * Description: monty interpreter
 * Return: 0 if success, 1 otherwise
 */
int main(int argc, char *argv[])
{
	void (*func_ptr)(stack_t **stack, unsigned int line_number) = NULL;
	char line[1000];

	monty_args.argv = NULL;
	monty_args.ln = 0;
	monty_args.top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_args.fd = fopen(argv[1], "r");
	if (monty_args.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, 1000, monty_args.fd)) != NULL)
	{
		monty_args.ln++;
		monty_args.argv = get_line_cmds(line);
		if (!monty_args.argv)
			continue;
		func_ptr = select_opcode(monty_args.argv[0]);
		if (!func_ptr)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", monty_args.ln, monty_args.argv[0]);
			fclose(monty_args.fd);
			free_dlistint(monty_args.top);
			free_command(monty_args.argv);
			exit(EXIT_FAILURE);
		}
		func_ptr(&monty_args.top, monty_args.ln);
		free_command(monty_args.argv);
	}
	fclose(monty_args.fd);
	free_dlistint(monty_args.top);
	return (0);
}
