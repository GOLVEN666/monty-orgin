#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

#define LIMITER " \n"

/* Structures Doubly linked lists */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

ssize_t _getline(char **line, size_t *line_size, FILE *stream);

void chooser(stack_t **head, char *token, unsigned int line);

void freeer(stack_t **head);

/* Prototypes basic operations */

void pall(stack_t **head, unsigned int line);
void push(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);
void add(stack_t **head, unsigned int line);
void sub(stack_t **head, unsigned int line);
void mul(stack_t **head, unsigned int line);
void _div(stack_t **head, unsigned int line);
void pstr(stack_t **head, unsigned int line);
void rotl(stack_t **head, unsigned int line);
void rotr(stack_t **head, unsigned int line);


#endif
