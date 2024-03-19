#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int status;
	pid_t id;

	switch (id=fork())
	{
	case -1:
		printf("child process was not open correctly\n");
		exit(-1);
		break;
	case 0:
		printf("child process was open correctly %d with parent %d\n", getpid(),getppid());
		sleep(20);
		printf("this print is after sleep()\n");
		exit(3);
	default:
		printf("parent process and before wait %d\n", getpid());
		id=wait(&status);// you can pass NULL to wait function when you are not interested in the status the child proces terminated
		printf("parent procces print after wait with status %d and return proc id is %d\n",status,id);
		break;
	}
}