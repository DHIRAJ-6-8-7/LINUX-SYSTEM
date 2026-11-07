#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char message[] = "hello through FIFO";

	int fd = open("/tmp/myfifo", O_WRONLY);

	if(fd == -1){
		perror("open");
		return 1;
	}

	write(fd, message, sizeof(message));
	close(fd);
	return 0;
}
