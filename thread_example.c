#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *worker(void *arg){
	printf("Worker thread is running\n");

	printf("Thread ID: %lu\n",(unsigned long)pthread_self());
	return NULL;
}

int main(){
	pthread_t thread;

	int result = pthread_create(&thread, NULL, worker, NULL);
	if(result != 0){
		printf("Thread creation failed\n");		
		return 1;
	}
	printf("main thread is runnign\n");
	pthread_join(thread,NULL);
	printf("Worker thread findished\n");	
	return 0;
}

