#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    int status;

    pid = fork();
    
    if (pid == 0){
        execl("/bin/mkdir", "mkdir", "OperatingSystem", NULL);
        perror("Child process failed to exec!");
        return 1;
    }
    if (pid != wait(NULL)){
        perror("Parent process failed to wait due to signal or error!");
        return 1;
    }
    return 0;
}