#ifndef COMMAND_H
#define COMMAND_H

#define MAX_INPUT_LENGTH 256
#define MAX_ARGS_COUNT 64

typedef struct{
    char* argv[MAX_ARGS_COUNT+1];
    char* input_file[(int)(MAX_ARGS_COUNT/2)];
    char* output_file[(int)(MAX_ARGS_COUNT/2)];
    int input_flag;
    int output_flag;
    int argc;
    int success;
}Command;

#endif //COMMAND_H