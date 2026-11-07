#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(){
	int pipefd[2];

	if (pipe(pipefd) == -1) {
		perror("pipe");
		return 1;
	}

	pid_t pid = fork();

	if(pid<0){
		perror("fork");
		return 1;
	}

	if (pid == 0){
		close(pipefd[1]);
		char buffer[100];
		ssize_t byte = read(
				pipefd[0],
			       	buffer,
			       	sizeof(buffer)-1
				);

		if (byte>0){
			buffer[byte] = '\0';
			printf("child received: %s\n", buffer);
		}
		close(pipefd[0]);
	}
	else {
		close(pipefd[0]);
		char message[]="hello from parent process";
		write(
				pipefd[1],
				message,
				strlen(message)
		     );
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
	}
	return 0;
}

