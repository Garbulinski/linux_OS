#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
int main(void )
{
	pid_t child;
	pid_t ret_cild;
	int status=0;

	switch (child=fork())
	{
	case -1:
		printf("child proccess was not oper correctly\n");
		break;
	case 0:
		printf("child block is executed %d\n",getpid());
		sleep(10);
		exit(1);
		break;
	
	default:
		printf("print before wait in parent proc %d\n",getpid());
		ret_cild=waitpid(80,&status, 0);
		if(ret_cild==-1)
		{
			perror("Error is: ");
			printf("wait pid returned error %d\n",errno);
		}
		printf("printf after  wait execution of child %d with status %d\n", ret_cild, status);
		break;
	}
	return 0;
}