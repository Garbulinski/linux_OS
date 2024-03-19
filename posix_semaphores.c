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

	sem = sem_open("/sem2",O_RDWR | O_CREAT, 0660, 2);

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

	printf("semafore value is %d\n", sval);
	sem_wait(sem);
	sem_getvalue(sem,&sval);

	printf("semafore value after wait is %d\n", sval);
	printf("Process executing after wait\n \n");
	sleep(20);
	printf("Process finished executing\n \n");
	
	sem_post(sem);
	sem_getvalue(sem,&sval);
	printf("process finished executing and sem was increased with value %d\n",sval);

	sem_unlink("/sem2");
}