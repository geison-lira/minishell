#include <cliparser/parser.h>

ParserState shell_parser(){
    char usr_input[MAX_INPUT_LENGTH];
    ParserState state = {0};
    if(fgets(usr_input, sizeof(usr_input), stdin) == NULL){
        fprintf(stderr, "parser error: An unexpected error ocurred while reading user input");
        return state;
    }
    if(strchr(usr_input, '\n') == NULL){
        fprintf(stderr, "parser error: Input exceed maximum supported length of %d characters\n", MAX_INPUT_LENGTH - 2);
        for(int input_flush = '\0'; input_flush != '\n' && input_flush != EOF; input_flush = getchar()){}
        return state;
    }
    usr_input[strcspn(usr_input, "\n")] = '\0';
    char* arg = strtok(usr_input, " ");
    for(state.argc = 0; arg != NULL && state.argc < MAX_ARGS_COUNT - 1; state.argc++){
        state.argv[state.argc] = arg;
        arg = strtok(NULL, " ");
    }
    state.argv[state.argc] = arg;
    if(arg != NULL){
        fprintf(stderr, "parser error: Input exceeds maximum supported number of %d arguments\n", MAX_ARGS_COUNT - 1);
        return state;
    }
    state.success = 1;
    return state;
}