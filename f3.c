#include "monty.h"

/**
* swap - Swaps the top two elements of the stack.
* @head: Head of the list
* @line: Number of the line
* Return: Void - Nothing
**/

void swap(stack_t **head, unsigned int line)
{
int tmp; /* Temporal variable for swap */

/* Verify If the stack contains less than two elements */
if (head == NULL || *head == NULL || (*head)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line);
exit(EXIT_FAILURE);
}

tmp = (*head)->n;
(*head)->n = (*head)->next->n;
(*head)->next->n = tmp;
}

/**
* nop - Doesn’t do anything.
* @head: Head of the list
* @line: Number of the line
* Return: Void - Nothing
**/
void nop(stack_t **head, unsigned int line)
{
/* Attribute unused*/
(void) head;
(void) line;
}

/**
* pstr - pstr
* @head: Head of the list
* @line: Number of the line
* Return: Void - Nothing
**/
void pstr(stack_t **head, unsigned int line)
{
stack_t *current = *head;

(void)line;

while (current != NULL && current->n > 0 && current->n <= 127)
{
if (current->n == '\0')
break;

putchar(current->n);
current = current->next;
}

putchar('\n');
}

/**
 * rotl - Rotates the stack to the top
 * @head: Head of the list
 * @line: Number of the line
 * Return: Void - Nothing
 **/
void rotl(stack_t **head, unsigned int line)
{
stack_t *temp, *last;

(void)line;

if (*head == NULL || (*head)->next == NULL)
return;

temp = *head;
last = *head;

while (last->next != NULL)
last = last->next;

*head = (*head)->next;
(*head)->prev = NULL;
last->next = temp;
temp->prev = last;
temp->next = NULL;
}


/**
 * rotr - Rotates the stack to the bottom
 * @head: Head of the list
 * @line: Number of the line
 * Return: Void - Nothing
 **/
void rotr(stack_t **head, unsigned int line)
{
stack_t *last, *second_last;

(void)line;

if (*head == NULL || (*head)->next == NULL)
return;

last = *head;
second_last = *head;

while (last->next != NULL)
{
second_last = last;
last = last->next;
}

second_last->next = NULL;
last->next = *head;
last->prev = NULL;
(*head)->prev = last;
*head = last;
}