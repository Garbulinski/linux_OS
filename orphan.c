#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t child;


	switch (child = fork())
	{
	case -1:
		printf("child was not created succesfully \n");
		break;
	case 0:
		printf("child started executing with id %d and parent id %d\n",getpid(),getppid());
		sleep(10);
		printf("this execution is printed after 10 second sleep with id %d and parrent id %d\n", getpid(), getppid());
		break;
	default:
		printf("parent process is executing %d\n", getpid());
		return 1;
		break;
	}
	return 0;
}