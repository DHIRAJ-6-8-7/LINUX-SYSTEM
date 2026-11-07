#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	char buffer[100];

	int fd = open("/tmp/myfifo", O_RDONLY);

	if(fd == -1){
		perror("open");
		return 1;
	}

	ssize_t bytes = read(fd, buffer, sizeof(buffer)-1);;

	if(bytes>0){
		buffer[bytes] = '\0';
		printf("Received: %s\n", buffer);
	}
	close(fd);
	return 0;
}
