#include <cliparser/parser.h>

void shell_parser(){
    char usr_input[MAX_INPUT_LENGTH];
    if(fgets(usr_input, sizeof(usr_input), stdin) != NULL){
        if(strchr(usr_input, '\n') == NULL){
            printf("error: Input exceed maximum supported length of %d characters\n", MAX_INPUT_LENGTH - 2);
            for(int input_flush = '\0'; input_flush != '\n' && input_flush != EOF; input_flush = getchar()){}
        }
    }
}