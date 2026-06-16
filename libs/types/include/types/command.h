#ifndef COMMAND_H
#define COMMAND_H

#define MAX_INPUT_LENGTH 256
#define MAX_ARGS_COUNT 64
#define MAX_IOARGS_COUNT ((int)(MAX_ARGS_COUNT / 2))

typedef struct{
    char* argv[MAX_ARGS_COUNT+1];
    char* input_file[MAX_IOARGS_COUNT];
    char* output_file[MAX_IOARGS_COUNT];
    int input_flag;
    int output_flag;
    int argc;
    int success;
}Command;

#endif //COMMAND_H