#include <cliexecutor/executor.h>

void shell_executor(char* argv[]){
    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        exit(1);
    }
    else if(pid == 0){
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