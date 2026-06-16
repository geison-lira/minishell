#ifndef COMMAND_H
#define COMMAND_H

#define MAX_INPUT_LENGTH 256
#define MAX_ARGS_COUNT 64
#define MAX_PIPEARGS_COUNT ((int)(MAX_ARGS_COUNT / 2))

typedef struct{
    char* argv[MAX_ARGS_COUNT+1];
    char* input_pipe[MAX_PIPEARGS_COUNT];
    char* output_pipe[MAX_PIPEARGS_COUNT];
    char* input_file;
    char* output_file;
    int argc;
    int success;
}Command;

#endif //COMMAND_H