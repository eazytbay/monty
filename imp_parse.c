#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * unique_parse_line - A function that  Tokenizes a line of text,
 * storing it in line struct
 * @line: The Struct  that includes the contents of the line  and line number
 * @buffer: The particular String of text read from the script file
 *
 * Return: Nothing
 */
void unique_parse_line(unique_line_t *line, char *buffer)
{
unsigned int x;
char *symb = NULL;
line->content = malloc(sizeof(char *) * 3);
if (!line->content)
{
fprintf(stderr, "Error: malloc failed");
exit(EXIT_FAILURE);
}
symb = strtok(buffer, " '\n'");
x = 0;
while (symb && x < 2)
{
line->content[x] = symb;
symb = strtok(NULL, " \n");
x++;
}
line->content[x] = NULL;
}
/**
 * unique_parse_file - A function that Reads and parses
 * file one line at a time
 * @file: The file script that's to be read
 *
 * Return: Nothing
 */
void unique_parse_file(FILE *file)
{
size_t pize = 0;
unique_meta_t *meta = NULL;
unique_line_t line;
meta = malloc(sizeof(unique_meta_t));
if (!meta)
{
fprintf(stderr, "Error: malloc failed");
exit(EXIT_FAILURE);
}
line.number = 0;
line.content = NULL;
meta->file = file;
meta->structure = NULL;
meta->buffer = NULL;
for (line.number = 0; fgets(meta->buffer, pize, meta->file) != 
NULL; line.number++)
{
unique_parse_line(&line, meta->buffer);
if (line.content)
get_unique_func(line, meta)(&(meta->structure), line.number);
}
free(meta->buffer);
unique_free_structure(&(meta->structure));
fclose(meta->file);
free(meta);
}
