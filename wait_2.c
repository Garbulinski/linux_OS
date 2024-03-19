#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void )
{
	pid_t child1;
	pid_t child2;
	int status=0;
	switch (child1=fork())
	{
	case -1:
		printf("child process was not open correctly\n");
		exit(-1);
		break;
	case 0:
		printf("first child process was open correctly %d with parent %d\n", getpid(),getppid());
		sleep(20);
		printf("this print is after sleep()\n");
		exit(3);
	default:
		child2=fork();
		if(child2==-1)
		{
			printf("opening second child failed \n");
			exit(-1);
		}
		else if( child2==0)
		{
			printf("second child process was open correctly %d with parent %d\n", getpid(),getppid());
			sleep(10);
			printf("this print is after sleep()\n");
			exit(1);
		}
		printf("parent process and before wait %d\n", getpid());
		child1=wait(&status);// you can pass NULL to wait function when you are not interested in the status the child proces terminated
		printf("child %d was terminated with status %d\n",child1,status);

		child1=wait(&status);// you can pass NULL to wait function when you are not interested in the status the child proces terminated
		printf("child %d was terminated with status %d\n",child1,status);

		break;
	}
	return 0;
}
