#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    int status;

    pid = fork();
    if(pid == 0){
        execl("/bin/mkdir", "mkdir", "newdir", NULL);
        perror("execl");
        exit(1);
    }
    else if(pid > 0){
        wait(&status);
        printf("Parent process\n");
        printf("Child process is done\n");
    }
    else{
        perror("fork");
        exit(1);
    }
    return 0;
}