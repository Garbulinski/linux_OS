#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
static void *thread_function(void *arg)
{
	char *str=(char*) arg;
	printf("thread function is called with argument %s and pid %d\n", str,getpid());
	sleep(2);
	printf("thread function exiting\n");
	return 0;
}
int main(void)
{
	pthread_t t1;
	int s=0;
	s=pthread_create(&t1,NULL, thread_function,"HELLO world");
	if(s!=0)
	{
		printf("thread was no created correctly \n");
	}
	printf("thread was created and proc id %d\n",getpid());
	sleep(5);
	printf("main function is terminated\n");
	return 0;
}