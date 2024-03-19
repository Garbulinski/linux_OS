#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
static int global=0;
sem_t sem;

static void *thread_funct(void *arg)
{
	int i=0;
	int loc;
	int ret;
	printf("thread %s started executing\n", (char *)arg);

	ret=sem_wait(&sem);
	
	if(ret==-1)
	{
		printf("sem wait was not done correctly\n");
	}
	sem_getvalue(&sem,&ret);
	printf("sem value %d arg %s\n",ret, (char *)arg);
	for(i=0;i<100;i++)
	{
		loc=global;
		loc++;
		global=loc;
	}

	ret=sem_post(&sem);
	if(ret==-1)
	{
		printf("sem_post was not done correctly\n");
	}
	printf("thread %s finished executing \n",(char*) arg);
	return NULL;
}
int main(void)
{
	int flag;
	pthread_t t1,t2,t3;
	flag=pthread_create(&t1,NULL,thread_funct,"thr1");
	if(flag==-1)
	{
		printf("thread1 was not created correctly \n");
	}

	flag=pthread_create(&t2,NULL,thread_funct,"thr2");
	if(flag==-1)
	{
		printf("thread2 was not created correctly \n");
	}

	flag=pthread_create(&t3,NULL,thread_funct,"thr3");

	if(flag==-1)
	{
		printf("thread3 was not created correctly \n");
	}
	printf("printf after join1\n");
	if(sem_init(&sem, 0,3)==-1)
	{
		printf("semaphore initialization was not made\n");
	}
	if(pthread_join(t1,NULL)!=0)
	{
		printf("t1 join was not made correctly \n");
	}
	printf("printf after join1\n");
	if(pthread_join(t2,NULL)!=0)
	{
		printf("t2 join was not made correctly \n");
	}
	printf("printf after join2\n");
	if(pthread_join(t3,NULL)!=0)
	{
		printf("t3 join was not made correctly \n");
	}
	printf("printf after join3\n");

	printf("global variable is %d\n",global);
	sem_close(&sem);
	return 0;
}