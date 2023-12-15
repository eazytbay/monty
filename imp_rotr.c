#include "monty.h"
/**
 * unique_rotl - A function that Rotates the stack to the very top
 * @structure: Points to the head node pointer of stack
 * @line_number: The line number
 * Return: Absolutely Nothing.
 */
void unique_rotl(stack_t **structure, unsigned int line_number)
{
stack_t *ephem;
int var1, var2;
(void)line_number;
if (structure == NULL || *structure == NULL)
{
unique_nop(structure, line_number);
}
var1 = (*structure)->n;
ephem = *structure;
for (; ephem != NULL; ephem = ephem->next)
{
if (ephem->next == NULL)
break;
}
var2 = ephem->n;
(*structure)->n = var2;
ephem->n = var1;
}
/**
 * unique_rotlop - A function that Rotates stack to the very left
 * @structure: Points to the head node pointer of stack
 * @line_number: The line number
 * Return: Absolutely Nothing.
 */
void unique_rotlop(stack_t **structure, unsigned int line_number)
{
stack_t *end, *ephem;
(void)line_number;
if (!structure || !(*structure) || !((*structure)->next))
return;
ephem = *structure;
end = ephem;
for (; end->next != NULL; end = end->next)
;
end->next = ephem;
ephem->prev = end;
ephem->next->prev = NULL;
*structure = ephem->next;
ephem->next = NULL;
}
/**
 * unique_rotrop - A function that Rotates stack to the very right
 * @structure: Points to the head node pointer of stack
 * @line_number: The line number
 * Return: Absolutely Nothing.
 */
void unique_rotrop(stack_t **structure, unsigned int line_number)
{
stack_t *end, *ephem;
(void)line_number;
if (!structure || !(*structure) || !((*structure)->next))
return;
ephem = *structure;
end = ephem;
for (; end->next != NULL; end = end->next)
;
end->prev->next = NULL;
end->prev = NULL;
ephem->prev = end;
end->next = ephem;
*structure = end;
}
/**
 * unique_qpush -  A function that Pushes for queue instead of stack
 * @structure: Points to the head node pointer of stack
 * @line_number: The line number
 * Return: Absolutely Nothing.
 */
void unique_qpush(stack_t **structure, unsigned int line_number)
{
stack_t *end, *mo;
if (structure == NULL)
{
fprintf(stderr, "L%d: stack not found\n", line_number);
exit(EXIT_FAILURE);
}
mo = malloc(sizeof(stack_t));
if (mo == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
unique_free_structure(structure);
exit(EXIT_FAILURE);
}
end = NULL;
if (*structure)
{
end = *structure;
for (; end->next != NULL; end = end->next)
;
end->next = mo;
}
else
*structure = mo;
mo->prev = end;
mo->next = NULL;
mo->n = arg.arg;
}
