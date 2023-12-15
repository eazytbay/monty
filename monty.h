#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * struct arg_s - structure for holding unique arguments
 * @arg: integer argument
 * @flag: flag indicating a condition
 *
 * Description: structure for handling unique arguments
 */
typedef struct arg_s
{
    int arg;
    int flag;
} arg_t;

extern arg_t arg;

/**
 * struct stack_s - doubly linked list representation of a unique structure
 * @n: integer value
 * @previous: points to the previous element of the structure
 * @next: points to the next element of the structure
 *
 * Description: doubly linked list node structure for a unique project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * instruction_s - opcode and its function
 * @opcode: the opcode
 * @function: function to handle the opcode
 *
 * Description: opcode and its function for a unique project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **structure, unsigned int line_number);
} instruction_t;

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
    stack_t *structure;
    FILE *file;
} unique_meta_t;
/* Important functions */
void (*get_unique_func(unique_line_t line, unique_meta_t *meta))(stack_t **, unsigned int);
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
void unique_sub(stack_t **structure, unsigned int line_number);
void unique_add(stack_t **structure, unsigned int line_number);
void unique_div(stack_t **structure, unsigned int line_number);
void unique_mul(stack_t **structure, unsigned int line_number);
void unique_mod(stack_t **structure, unsigned int line_number);

#endif /* _MONTY_H */
