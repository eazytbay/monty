#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct unique_arg - structure for holding unique arguments
 * @argument: integer argument
 * @flag: flag indicating a condition
 *
 * Description: structure for handling unique arguments
 */
typedef struct unique_arg_s
{
    int argument;
    int flag;
} unique_arg_t;

extern unique_arg_t unique_arg;

/**
 * struct unique_node - doubly linked list representation of a unique structure
 * @value: integer value
 * @previous: points to the previous element of the structure
 * @next: points to the next element of the structure
 *
 * Description: doubly linked list node structure for a unique project
 */
typedef struct unique_node_s
{
    int value;
    struct unique_node_s *previous;
    struct unique_node_s *next;
} unique_node_t;

/**
 * struct unique_instruction - opcode and its function
 * @opcode: the opcode
 * @function: function to handle the opcode
 *
 * Description: opcode and its function for a unique project
 */
typedef struct unique_instruction_s
{
    char *opcode;
    void (*function)(unique_node_t **structure, unsigned int line_number);
} unique_instruction_t;

/**
 * struct unique_line - contents of line and corresponding number
 * @contents: array of tokens read from the line
 * @number: the line number
 *
 * Description: contents of a line and corresponding number for a unique project
 */
typedef struct unique_line_s
{
    unsigned int number;
    char **content;
} unique_line_t;

/**
 * struct unique_meta - metadata for unique project
 * @buffer: buffer for file reading
 * @structure: unique structure
 * @file: file pointer
 *
 * Description: metadata for a unique project
 */
typedef struct unique_meta_s
{
    char *buffer;
    unique_node_t *structure;
    FILE *file;
} unique_meta_t;

/* Important functions */
void (*get_unique_func(unique_line_t line, unique_meta_t *meta))(unique_node_t **, unsigned int);
int unique_isalpha(int c);

/* Parse functions */
void unique_parse_file(FILE *file);
void unique_parse_line(unique_line_t *line, char *buffer);

/* Verification functions */
bool unique_comment_check(unique_line_t line);
void unique_push_check(unique_line_t line, unique_meta_t *meta, char *opcode);

/* Structure manipulation functions */
void unique_push(stack_t **structure, unsigned int line_number);
void unique_pall(stack_t **structure, unsigned int line_number);
void unique_pint(stack_t **structure, unsigned int line_number);
void unique_pop(stack_t **structure, unsigned int line_number);
void unique_swap(stack_t **structure, unsigned int line_number);
void unique_nop(stack_t **structure, unsigned int line_number);
void unique_rotl(stack_t **structure, unsigned int line_number);
void unique_rotlop(stack_t **structure, unsigned int line_number);
void unique_rotrop(stack_t **structure, unsigned int line_number);
void unique_pchar(stack_t **structure, unsigned int line_number);
void unique_pstr(stack_t **structure, unsigned int line_number);
void unique_free_structure(stack_t **structure);
void unique_qpush(stack_t **structure, unsigned int line_number);
void unique_addqu(stack_t **structure, unsigned int line_number);
void unique_addst(stack_t **structure, unsigned int line_number);

/* Unique math functions */
void unique_subtract(unique_node_t **structure, unsigned int line_number);
void unique_add(unique_node_t **structure, unsigned int line_number);
void unique_divide(unique_node_t **structure, unsigned int line_number);
void unique_multiply(unique_node_t **structure, unsigned int line_number);
void unique_modulus(unique_node_t **structure, unsigned int line_number);

#endif /* _MONTY_H */
