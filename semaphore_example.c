#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t resource_limit;

void *worker(void *arg){
	int id = *(int *)arg;
	sem_wait(&resource_limit);
	printf("Worker %d acquired resource\n", id);
	sleep(2);
	printf("Worker %d released resource\n", id);
	sem_post(&resource_limit);
	return NULL;
}

int main(){
	pthread_t threads[5];
	int ids[5] = {1,2,3,4,5};
	sem_init(&resource_limit, 0, 2);
	for (int i=0; i<5; i++){
		pthread_create(
				&threads[i],
				NULL,
				worker,
				&ids[i]
			      );
	}
	for (int i=0; i<5; i++){
		pthread_join(threads[i], NULL);
	}

	sem_destroy(&resource_limit);
	return 0;
}
