#include "monty.h"

/**
* push - Function for push an element to the stack.
* @head: Head of the list
* @line: Number of the line
* Return: void - nothing
**/

void push(stack_t **head, unsigned int line)
{
stack_t *new_node = NULL;
int count = 0;
char *str_test = strtok(NULL, LIMITER);

if (!str_test)/* if <int> is not an int or if no argument given to push */
{
fprintf(stderr, "L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}

while (str_test[count] != '\0')
{
if (!isdigit(str_test[count]) && str_test[count] != '-')
{
fprintf(stderr, "L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
count++;
}
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = atoi(str_test);
new_node->prev = NULL;

if (*head)
{
new_node->next = (*head);
(*head)->prev = new_node;
(*head) = new_node;
}
else
{
(*head) = new_node;
new_node->next = NULL;
}
}

/**
* pall - Prints all the values on the stack,
* starting from the top of the stack.
* @head: Head of the list
* @line: Number of the line
* Return: void - nothing
**/

void pall(stack_t **head, unsigned int line __attribute__((unused)))
{
/* Transfer values to not modify original list */
stack_t *curr = *head;

while (curr)
{
printf("%d\n", curr->n);
curr = curr->next;
}
}

/**
* pint - prints the value at the top of the stack,
* followed by a new line.
* @head: Head of the list
* @line: Number of the line
* Return: void - nothing
**/

void pint(stack_t **head, unsigned int line)
{
/* str_test if the stack is empty */
if (head == NULL || *head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

/**
* pop - Removes the top element of the stack.
* @head: Head of the list
* @line: Number of the line
* Return: void - nothing
**/
void pop(stack_t **head, unsigned int line)
{
stack_t *new_list = *head;

if (head == NULL || *head == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line);
exit(EXIT_FAILURE);
}
new_list = (*head)->next;
free(*head);
*head = new_list;
}
