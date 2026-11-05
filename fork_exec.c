#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid = fork();
	
	if (pid<0){
		perror("fork failed");
		return 1;
	}

	if(pid == 0){
		printf("child process started\n");
		printf("Child PID: %d\n", pid);

	char *args[] = {"ls", "-l", NULL};

	execvp("ls", args);

	perror("execvp failed");
	exit(1);
	} else {
	printf("parent proceess waiting for child...\n");
	wait(NULL);
	printf("child execution finished\n");
	}
	return 0;
}
