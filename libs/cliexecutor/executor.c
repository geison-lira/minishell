#include <cliexecutor/executor.h>

void shell_executor(char* argv[], char* input_file, char* output_file){
    pid_t pid = fork();
    int fd_input;
    int fd_output;
    if(pid < 0){
        perror("fork error");
        exit(1);
    }
    else if(pid == 0){
        if(input_file != NULL){
            fd_input = open(input_file, O_RDONLY);
            if(fd_input >= 0){
                dup2(fd_input, STDIN_FILENO);
                close(fd_input);
            }
            else{
                perror("dup2 error");
            }
        }
        if(output_file != NULL){
            fd_output = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if(fd_output >= 0){
                dup2(fd_output, STDOUT_FILENO);
                close(fd_output);
            }
            else{
                perror("dup2 error");
            }
        }
        execv(argv[0], argv);
        perror("execv error");
        exit(1);
    }
    else{
        int status;
        pid_t terminated_pid = wait(&status);
        if ((WIFEXITED(status) && WEXITSTATUS(status) != 0) || WIFSIGNALED(status)) {
            fprintf(stderr, "executor error: Child process failed to execute\n");
        }
    }
}