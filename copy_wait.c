#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	pid_t child1;
	pid_t child2;

	int status;

	child1 = fork();
	if(child1 == -1)
	{
		printf("process creation failed\n");
	}
	else if(child1 == 0)
	{
		printf("executed this print from child %d with parent %d\n", getpid(), getppid());
		sleep(10);
		exit(0);
	}
	else
	{
		child2 = fork();
		if(child2 == -1)
		{
			printf("process creation failed\n");
		}
		else if(child2 == 0)
		{
			printf("executed this print from child %d with parent %d\n", getpid(), getppid());
			sleep(10);
			exit(1);
		}

		printf("execution from parent process started %d\n",getpid());

		int res =0 ;
		res = waitpid(child1, &status, 0);

		if(res == -1)
		{
			perror("Error is: ");
			printf("wait pid returned error %d\n",errno);
		}

		printf("parent execution after termination of child %d with status %d\n",res, status);

		res = waitpid(child2,&status,0);

		if(res == -1)
		{
			perror("Error is: ");
			printf("wait pid returned error %d\n",errno);
		}
		printf("parent execution after termination of child %d with status %d\n",res, status);

		printf("parent execution terminated\n");
	}
	return 0;
}