#include<stdio.h>
#include<pthread.h>

void *worker(void *arg){
	int worker_id = *(int *) arg;
	printf("Woker %d is processing\n", worker_id);

	return NULL;
}
int main(){
	pthread_t thread[3];
	int ids[3] = {1,2,3};
	for(int i=0;i<3;i++){
		int result = pthread_create(&thread[i], NULL, worker, &ids[i]);
		if(result!=0){
			printf("Thread Creation failed\n");
			return 1;
		}
	}

	for(int i=0;i<3;i++){
		pthread_join(thread[i],NULL);
	}

	printf("All workers  finished\n");
	return 0;
}
