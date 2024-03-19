#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
int flag=0;
char buf[100];
static void *provider_funct(void *arg)
{
	printf("threada provider funct is scheduled first\n");
	sleep(1);
	pthread_mutex_lock(&mutex);
	printf("critical data is created by threadA\n");
	strcpy(buf,"This data is creaded by buffer\n");
	flag=1;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);
	return 0;
}
static void *consumer_funct(void *argc)
{
	printf("threadb consumer funct is scheduled first\n");
	pthread_mutex_lock(&mutex);
	printf("critical data is created by threadb\n");
	if(flag==0)
	{
		pthread_cond_wait(&cond,&mutex);
	}

	printf("this is executed form thread B bconsumer funct prints %s and flag %d is set in threada\n",buf,flag);
	pthread_mutex_unlock(&mutex);
	return 0;
}
int main(void)
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1,NULL,provider_funct,NULL);
	pthread_create(&t2,NULL,consumer_funct,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
}