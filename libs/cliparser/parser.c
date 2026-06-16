#include <cliparser/parser.h>

Command shell_parser(){
    char usr_input[MAX_INPUT_LENGTH+2];
    Command state = {0};
    if(fgets(usr_input, sizeof(usr_input), stdin) == NULL){
        fprintf(stderr, "parser error: An unexpected error ocurred while reading user input\n");
        return state;
    }
    if(strchr(usr_input, '\n') == NULL){
        fprintf(stderr, "parser error: Input exceed maximum supported length of %d characters\n", MAX_INPUT_LENGTH);
        for(int input_flush = '\0'; input_flush != '\n' && input_flush != EOF; input_flush = getchar()){}
        return state;
    }
    usr_input[strcspn(usr_input, "\n")] = '\0';
    char* arg = strtok(usr_input, " ");
    for(state.argc = 0; arg != NULL && state.argc < MAX_ARGS_COUNT; state.argc++){
        state.argv[state.argc] = strdup(arg);
        arg = strtok(NULL, " ");
    }
    state.argv[state.argc] = arg;
    if(arg != NULL){
        fprintf(stderr, "parser error: Input exceeds maximum supported number of %d arguments\n", MAX_ARGS_COUNT);
        return state;
    }
    for(int i = 0; i < state.argc; i++){
        if(strcmp(state.argv[i], ">") == 0){
            if(i == 0){
                fprintf(stderr, "parser error: No program binary informed\n");
                return state;
            }
            if(state.output_flag){
                fprintf(stderr, "parser error: More than one output file informed\n");
                return state;
            }
            if(state.argc <= i+1){
                fprintf(stderr, "parser error: No output file informed\n");
                return state;
            }
            state.output_file[0] = state.argv[i+1];
            for(int j = i; j < state.argc - 1; j++){
                state.argv[j] = state.argv[j+2];
            }
            state.output_flag = 1;
            state.argc -= 2;
            i--;
        }
        if(strcmp(state.argv[i], "<") == 0){
            if(i == 0){
                fprintf(stderr, "parser error: No program binary informed\n");
                return state;
            }
            if(state.input_flag){
                fprintf(stderr, "parser error: More than one input file informed\n");
                return state;
            }
            if(state.argc <= i+1){
                fprintf(stderr, "parser error: No input file informed\n");
                return state;
            }
            state.input_file[0] = state.argv[i+1];
            for(int j = i; j < state.argc - 1; j++){
                state.argv[j] = state.argv[j+2];
            }
            state.input_flag = 1;
            state.argc -=2;
            i--;
        }
    }
    state.success = 1;
    return state;
}

void shell_cleaner(Command state){
    for(int i = 0; i < state.argc; i++){
        if(state.argv[i] != NULL){
            free(state.argv[i]);
            state.argv[i] = NULL;
        }
        if(state.input_file[i] != NULL){
            free(state.input_file[i]);
            state.input_file[i] = NULL;
        }
        if(state.output_file[i] != NULL){
            free(state.output_file[i]);
            state.output_file[i] = NULL;
        }
    }
    state.input_flag = 0;
    state.output_flag = 0;
    state.argc = 0;
    state.success = 0;
}