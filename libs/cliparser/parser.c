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
            if(state.argc > i+1){
                state.output_file[0] = state.argv[i+1];
                for(int j = i; j < state.argc - 1; j++){
                    state.argv[j] = state.argv[j+2];
                }
                state.argc -= 2;
                i--;
            }
            else{
                 fprintf(stderr, "parser error: no output file informed\n");
                 return state;
            }
        }
        if(strcmp(state.argv[i], "<") == 0){
            if(state.argc > i+1){
                state.input_file[0] = state.argv[i+1];
                for(int j = i; j < state.argc - 1; j++){
                    state.argv[j] = state.argv[j+2];
                }
                state.argc -=2;
                i--;
            }
            else{
                fprintf(stderr, "parser error: no input file informed\n");
                return state;
            }
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
    state.argc = 0;
    state.success = 0;
}