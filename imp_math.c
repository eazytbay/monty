#include "monty.h"
/**
 * unique_add - A function that adds two top elements together
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_add(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
if (!(*structure) || !(*structure)->next)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
ephem = *structure;
(*structure)->next->n += (*structure)->n;
*structure = (*structure)->next;
(*structure)->prev = NULL;
free(ephem);
}
/**
 * unique_sub - A function that subtracts two top elements and saves
 * it in a second element
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_sub(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
if (!(*structure) || !(*structure)->next)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
ephem = *structure;
(*structure)->next->n -= (*structure)->n;
*structure = (*structure)->next;
(*structure)->prev = NULL;
free(ephem);
}
/**
 * unique_div - A function that divides the two top elements and saves
 * it in second element
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_div(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
if (!(*structure) || !(*structure)->next)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*structure)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
ephem = *structure;
(*structure)->next->n /= (*structure)->n;
*structure = (*structure)->next;
(*structure)->prev = NULL;
free(ephem);
}
/**
 * unique_mul - A function that multiplies the two top elements and saves
 * it in the second element
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_mul(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
if (!(*structure) || !(*structure)->next)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
ephem = *structure;
(*structure)->next->n *= (*structure)->n;
*structure = (*structure)->next;
(*structure)->prev = NULL;
free(ephem);
}
/**
 * unique_mod - A function that computes the rest of the division of the
 * second top element of the stack
 * @structure: points to the head node pointer of stack
 * @line_number: the line number
 * Return: Absolutely Nothing.
 */
void unique_mod(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
if (!(*structure) || !((*structure)->next))
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*structure)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
ephem = *structure;
(*structure)->next->n %= (*structure)->n;
*structure = (*structure)->next;
(*structure)->prev = NULL;
free(ephem);
}
