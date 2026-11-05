#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int number = 10;

    pid_t pid = fork();

    if (pid == 0) {
        number = 50;
        printf("Child number: %d\n", number);
    }
    else if (pid > 0) {
        printf("Parent number: %d\n", number);
    }

    return 0;
}

