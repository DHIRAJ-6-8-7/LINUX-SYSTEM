#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(){
	const char *name = "/my_shared_memory";
	const int SIZE = 4096;

	int fd = shm_open(
			name,
			O_CREAT | O_RDWR,
			0666
			);
	if(fd == -1){
		perror("shm_open");
		return 1;
	}

	if(ftruncate(fd, SIZE) == -1){
		perror("ftruncate");
		close(fd);
		shm_unlink(name);
		return 1;
	}
	char *ptr = mmap
			NULL,
			SIZE,
			PROT_READ | PROT_WRITE,
			MAP_SHARED,
			fd,
			0
			);
	if (ptr == MAP_FAILED){
		perror("mmap");
		close(fd);
		shm_unlink(name);
		return 1;
	}

	strcpy(ptr, "hello from shared memory");
	printf("Stored: %s\n", ptr);

	munmap(ptr, SIZE);
	close(fd);
	shm_unlink(name);
	return 0;
}

