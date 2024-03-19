#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void *joined_thread(void *arg)
{	
	// char *str=(char *)arg;
	int i =0;
	printf("thread funct started\n");
	pthread_detach(pthread_self());
	for(i=0;i<100;i++)
	{
		i++;
	}

	sleep(5);	
	printf("thread function exiting now\n");
}
int main(void )
{
	pthread_t t1;
	int s;

	s=pthread_create(&t1,NULL,joined_thread,NULL);
	if(s!=0)
	{
		printf("thread was not created correctly\n");
	}

	printf("main thread exiting now\n");
	pthread_exit(NULL);
}