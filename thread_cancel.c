#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void *cancel_thread(void *arg)
{	
	// char *str=(char *)arg;
	pthread_detach(pthread_self());
	while(1)
	{
		printf("thread funct printf\n");
		sleep(1);	
	}

	printf("thread function exiting now\n");
	return 0;
}

int main(void )
{
	pthread_t t1;
	int s;
	int i;
	s=pthread_create(&t1,NULL,cancel_thread,NULL);
	if(s!=0)
	{
		printf("thread was not created correctly\n");
	}

	for(i=0;i<10;i++)
	{
		printf("main thread i %d\n",i);
		sleep(2);
	}
	pthread_cancel(t1);
	printf("main thread exiting now\n");
	pthread_exit(NULL);
}