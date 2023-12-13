#include "monty.h"
/**
 * unique_pint - A function that prints the value at the top of stack
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_pint(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
if (structure == NULL || *structure == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
ephem = *structure;
for (; ephem; ephem = ephem->prev)
{
if (ephem->prev == NULL)
break;
}
printf("%d\n", ephem->n);
}
/**
 * unique_pop -A function that deletes the element at the top of a stack
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_pop(stack_t **structure, unsigned int line_number)
{
if (structure == NULL || *structure == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
if ((*structure)->next != NULL)
{
*structure = (*structure)->next;
free((*structure)->prev);
(*structure)->prev = NULL;
}
else
{
free(*structure);
*structure = NULL;
}
}
/**
 * unique_swap - A function that swaps the top two elements of the stack
 * @structure: pointer to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_swap(stack_t **structure, unsigned int line_number)
{
int ephem;
if (structure == NULL || *structure == NULL || !((*structure)->next))
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
ephem = (*structure)->n;
(*structure)->n = (*structure)->next->n;
(*structure)->next->n = ephem;
}
/**
 * unique_pchar -A function that prints char at top of stack
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Nothing.
 */
void unique_pchar(stack_t **structure, unsigned int line_number)
{
char a;
stack_t *ephem;
if (structure == NULL || *structure == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
ephem = *structure;
for (; ephem; ephem = ephem->prev)
{
if (ephem->prev == NULL)
break;
}
a = ephem->n;
if (unique_isalpha(ephem->n) == 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}
printf("%c\n", a);
}
/**
 * unique_pstr -A function that prints a string from ASCII
 * beginning from the top
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_pstr(stack_t **structure, unsigned int line_number)
{
int ind = 0;
char res[] = "";
char a;
stack_t *ephem;
ephem = *structure;
(void)line_number;
for (; ephem; ephem = ephem->next)
{
if (ephem->n == 0)
break;
if (unique_isalpha(ephem->n) == 0)
break;
a = ephem->n;
printf("%c", a);
res[ind] += a;
ind++;
}
printf("\n");
}
