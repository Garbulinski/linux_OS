#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
static void signal_handler(int signo)
{
	if(signo==SIGUSR1)
	{
		printf("signal was handled SIGUSR1\n");
	}
}
int main(void)
{
	pid_t child;
	int status;
	switch (child=fork())

	{
	case -1:
		printf("child was not created correctly\n");
		exit(EXIT_FAILURE);
		break;
	case 0:
		printf("printf before execv child was created correctly with pid %d\n",getpid());
		execl("./signal_user2","arg1","arg2","arg3",NULL);
		printf("this log will not be printed\n");
		exit(EXIT_FAILURE);
		break;
	default:

		printf("this log is printed from parent\n");
		if(signal(SIGUSR1,signal_handler)==SIG_ERR)
		{
			printf("signal was note handled correctly\n");
			exit(EXIT_FAILURE);
		}
		
		printf("log printed before wait in parent proc\n");
		sleep(2);
		kill(child,SIGUSR2);
		child= wait(&status);
		printf("parent child printf after wait parent proc id %d\n",getpid());
		printf("wait returned child %d with status %d\n", child, status);
		break;
	}
	return 0;
}