#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#define MAX_INPUT_LENGTH 256
#define MAX_ARGS_COUNT 64

typedef struct{
    char* argv[MAX_ARGS_COUNT+1];
    char* input_file;
    char* output_file;
    int argc;
    int success;
}ParserState;

ParserState shell_parser();

#endif