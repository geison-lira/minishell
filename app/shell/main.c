#include <cliprompt/prompt.h>
#include <cliparser/parser.h>

int main(){
    printf("Welcome to the miniature shell.\n");
    while(1){
        shell_prompt();
        shell_parser();
    }
}