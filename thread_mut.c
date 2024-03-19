#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
static int glob=0;
static pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
static void *thread_func(void *argc)
{
	int i=0;
	int loc;
	int ret;
	printf("thread funct was called\n");
	//ret=pthread_mutex_lock(&mutex);
	if(ret!=0)
	{
		printf("mutex was not locked\n");
	}
	for(i=0;i<1000;i++)
	{
		loc=glob;
		loc++;
		glob=loc;
	}
	
	//ret=pthread_mutex_unlock(&mutex);
	if(ret!=0)
	{
		printf("mutex was not locked\n");
	}
	return 0;
}

int main(void)
{
	pthread_t t1;
	pthread_t t2;
	int s=0;

	s=pthread_create(&t1,NULL,thread_func,NULL);
	if(s!=0)
	{
		printf("thread1 was not created correctly\n");
	}

	s=pthread_create(&t2,NULL,thread_func,NULL);
	if(s!=0)
	{
		printf("thread1 was not created correctly\n");
	}

	s=pthread_join(t1,NULL);
	if(s!=0)
	{
		printf("join 1 was not made correctly \n");
	}
	s=pthread_join(t2,NULL);
	if(s!=0)
	{
		printf("join 2 was not made correctly\n");
	}
	printf("glob %d\n",glob);
	return 0;
}