#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int sval;
	sem_t *sem;

	sem=sem_open("/sem2", O_RDWR);

	if(sem==SEM_FAILED)
	{
		printf("semafore failed to open\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("semafore opened correctly\n");
	}

	sem_getvalue(sem,&sval);
	printf("semafore value before wait  %d\n",sval);

	sem_wait(sem);
	printf("program 2 started executing instruction\n");
	sleep(10);
	sem_post(sem);
	printf("program 2 finished execution with sem value %d\n", sem_getvalue(sem,sval));
}