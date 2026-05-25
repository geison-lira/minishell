#include <cliprompt/prompt.h>
#include <cliparser/parser.h>
#include <cliexecutor/executor.h>

int main(){
    ParserState state;
    printf("Welcome to the miniature shell.\n");
    while(1){
        shell_prompt();
        state = shell_parser();
        if(state.success){
            shell_executor(state.argv);
        }
    }
}