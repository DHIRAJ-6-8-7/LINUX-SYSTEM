#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child is working...\n");
        exit(7);
    }

int status;
wait(&status);

if(WIFEXITED(status)){
printf("child exited with status: %d\n", WEXITSTATUS(status));
}
printf("Parent continues execution\n");

    return 0;
}
