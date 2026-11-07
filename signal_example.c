#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handle_signal(int signal_number){
	printf("Received signal: %d\n", signal_number);
}

int main(){
	signal(SIGINT, handle_signal);
	printf("Process is running. Press Ctrl+c\n");
	while(1){
		sleep(1);
	}
	return 0;
}
