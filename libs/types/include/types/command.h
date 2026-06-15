#ifndef COMMAND_H
#define COMMAND_H

#define MAX_INPUT_LENGTH 256
#define MAX_ARGS_COUNT 64

typedef struct{
    char* argv[MAX_ARGS_COUNT+1];
    char* input_file[MAX_ARGS_COUNT/2-1];
    char* output_file[MAX_ARGS_COUNT/2-1];
    int argc;
    int success;
}Command;

#endif //COMMAND_H