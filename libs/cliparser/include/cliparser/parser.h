#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#define MAX_INPUT_LENGTH 256
#define MAX_ARGS_COUNT 64

typedef struct{
    int argc;
    char* argv[MAX_ARGS_COUNT+1];
    int success;
    char* input_file;
    char* output_file;
}ParserState;

ParserState shell_parser();

#endif