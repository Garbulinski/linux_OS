#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void *joined_thread(void *arg)
{	
	// char *str=(char *)arg;
	int i =0;
	for(i=0;i<100;i++)
	{
		i++;
	}
	sleep(5);
	printf("thread function exiting now\n");
	if(i<500)
	{
		return "i<500";
	}
	else
	{
		return "i>500";
	}
}
int main(void )
{
	pthread_t t1;
	void *res;
	int s;

	s=pthread_create(&t1,NULL,joined_thread,NULL);
	if(s!=0)
	{
		printf("thread was not created correctly\n");
	}

	printf("printf fro main thread \n");
	#if 0
		s=pthread_join(t1,&res);
		if(s!=0)
		{
			printf("thread join was not made\n");
		}
		printf("main thread: thread return %s\n",(char *)res);
	#endif

	printf("main thread exiting now\n");
	return 0;
}