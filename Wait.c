#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 1; i <= 5; i++) {
            printf("Child: Still doing work... second %d\n", i);
            sleep(1);
        }

        printf("Child: Finished.\n");
        exit(0);
    } else if (pid > 0) {
        int status;
        int counter = 1;

        while (waitpid(pid, &status, WNOHANG) == 0) {
            printf("Parent counter: %d\n", counter++);
            sleep(1);
        }

        printf("Parent: Child is gone. Proceeding.\n");
    } else {
        printf("Fork failed.\n");
    }

    return 0;
}