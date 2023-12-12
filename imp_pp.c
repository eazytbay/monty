#include "monty.h"
/**
 * unique_push -A function that ensures that a node is
 * pushed to the top of stack
 * @structure: pointer to the head node pointer of stack
 * @line_number: the line number
 *
 * Return: Absolutely Nothing.
 */
void unique_push(stack_t **structure, unsigned int line_number)
{
stack_t *frs;
if (structure == NULL)
{
fprintf(stderr, "L%d: stack not found\n", line_number);
exit(EXIT_FAILURE);
}
frs = malloc(sizeof(stack_t));
if (frs == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
unique_free_structure(structure);
exit(EXIT_FAILURE);
}
frs->next = *structure;
frs->prev = NULL;
frs->n = arg.arg;
if (*structure)
{
(*structure)->prev = frs;
}
*sructure = frs;
}
/**
 * unique_pall - A function that outputs the data of all nodes in stack
 * @structure: pointer to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_pall(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
(void)line_number;
for (ephem = *stack; ephem != NULL; ephem = ephem->next)
{
printf("%d\n", temp->n);
}
}
/**
 * unique_free_structure - A function that frees without exception
 * all nodes in a stack
 * @structure: points to the head node pointer of stack
 *
 * Return: Absolutely Nothing.
 */
void unique_free_structure(stack_t **structure)
{
stack_t *ephem = NULL;
if (sttructure == NULL || *structure == NULL)
{
return;
}
for (; *structure != NULL; *structure = ephem)
{
ephem = (*structure)->next;
free(*structure);
}
}
/**
 * unique_nop -A function that does absolutely nothing
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_nop(stack_t **structure, unsigned int line_number)
{
(void)structure;
(void)line_number;
}
/**
 * unique_isalpha - A function that confirms if an int is in alphabet
 * @c: the int to be checked
 * Return: 1 if true, 0 if not
 */
int unique_isalpha(int c)
{
if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
{
return (1);
}
else
{
return (0);
}
}
