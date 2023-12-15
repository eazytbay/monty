#include "monty.h"
arg_t arg = {0, 0};

/**
 * unique_comment_check -A function that checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool unique_comment_check(unique_line_t line)
{
if (!line.content[0])
{
free(line.content);
return (true);
}
if (line.content[0][0] == '#')
{
free(line.content);
return (true);
}
return (false);
}
/**
 * unique_argument_check - A function that verifies the validity
 * of an argument
 * @token: the argument expected to be checked
 * Return: true if valid argument, else false
 */
bool unique_argument_check(char *token)
{
unsigned int x = 0;
if (!token)
return (false);
while (token[x] != '\0')
{
if (token[0] == '-')
{
x++;
continue;
}
if (token[x] < '0' || token[x] > '9')
{
return (false);
}
x++;
}
return (true);
}
/**
 * unique_push_check - A function that confirms if push opcode is
 * being used and sets global argument variable if true
 * @line: The struct that contains line contents and line number
 * @opcode: the opcode being compared
 * @meta: struct containing all memory allocated
 * Return: Absolutely Nothing.
 */
void unique_push_check(unique_line_t line, unique_meta_t *meta, char *opcode)
{
if ((strcmp(opcode, "push") == 0) && !unique_argument_check(line.content[1]))
{
free(line.content);
fprintf(stderr, "L%d: usage: push integer\n", line.number);
free(meta->buffer);
unique_free_structure(&(meta->structure));
fclose(meta->file);
free(meta);
exit(EXIT_FAILURE);
}
else if (strcmp(opcode, "push") == 0)
arg.arg = atoi(line.content[1]);
}
