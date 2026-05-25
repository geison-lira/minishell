#include <cliparser/parser.h>

void shell_parser(){
    char usr_input[MAX_INPUT_LENGTH];
    char* usr_argv[MAX_INPUT_ARGS];
    int usr_argc;
    if(fgets(usr_input, sizeof(usr_input), stdin) != NULL){
        if(strchr(usr_input, '\n') == NULL){
            printf("error: Input exceed maximum supported length of %d characters\n", MAX_INPUT_LENGTH - 2);
            for(int input_flush = '\0'; input_flush != '\n' && input_flush != EOF; input_flush = getchar()){}
        }
        else{
            char* arg = strtok(usr_input, " ");
            for(usr_argc = 0; arg != NULL && usr_argc < MAX_INPUT_ARGS; usr_argc++){
                usr_argv[usr_argc] = arg;
                arg = strtok(NULL, " ");
            }
            if(arg != NULL){
                printf("error: Input exceeds maximum supported number of %d arguments\n", MAX_INPUT_ARGS);
            }
        }
    }
}