/*
** EPITECH PROJECT, 2020
** warlock-C-libraries
** File description:
** arg_parser include for warlock-lib
*/

#ifndef ARG_PARSER_H_
#define ARG_PARSER_H_

typedef struct arg_t {
    char *option;
    char **content;
    char *stick_content;
    int value;
} arg_t;

typedef struct adapter_t {
    int ac;
    int i;
    char **argv;
} adapter_t;

arg_t **argument_parser(int ac, char **argv);
void load_parser_content(adapter_t *a, int *current, arg_t **list);
int load_parser_stick_content(adapter_t *a, int *current, arg_t **list);

#endif /* !ARG_PARSER_H_ */