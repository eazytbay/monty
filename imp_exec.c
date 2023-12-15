#include "monty.h"
/**
 * get_unique_func - A function that looks out for a match between
 * opcode and text and returns the corresponding function
 * @line: the struct that contains line contents and line number
 * @meta: A struct that contains all the memory allocated
 *
 * Return: pointer to the matching function
 */
void (*get_unique_func(unique_line_t line, unique_meta_t *meta))
(stack_t **, unsigned int)
{
unsigned int x;
instruction_t ops[] = {
{"unique_push", unique_push},
{"unique_pall", unique_pall},
{"unique_pint", unique_pint},
{"unique_pop", unique_pop},
{"unique_swap", unique_swap},
{"unique_add", unique_add},
{"unique_sub", unique_sub},
{"unique_div", unique_div},
{"unique_mul", unique_mul},
{"unique_mod", unique_mod},
{"unique_nop", unique_nop},
{"unique_pchar", unique_pchar},
{"unique_pstr", unique_pstr},
{"unique_rotl", unique_rotlop},
{"unique_rotr", unique_rotrop},
{"stack", unique_addst},
{"queue", unique_addqu},
{NULL, NULL}
};
if (unique_comment_check(line))
return (unique_nop);
for (x = 0; ops[x].opcode; x++)
{
if (strcmp(ops[x].opcode, line.content[0]) == 0)
{
unique_push_check(line, meta, ops[x].opcode);
if (arg.flag == 1 && strcmp(ops[x].opcode, "push") == 0)
{
if (line.content)
free(line.content);
return (unique_qpush);
}
free(line.content);
return (ops[x].f);
}
}
fprintf(stderr, "L%d: unknown instruction %s\n", line.number, line.content[0]);
free(line.content);
free(meta->buffer);
unique_free_structure(&(meta->structure));
fclose(meta->file);
free(meta);
exit(EXIT_FAILURE);
}
