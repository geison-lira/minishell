#include <stdio.h>
#include <string.h>
#define MAX_INPUT_LENGTH 258
#define MAX_ARGS_COUNT 65

typedef struct{
    int argc;
    char* argv[MAX_ARGS_COUNT];
    int success;
}ParserState;

ParserState shell_parser();