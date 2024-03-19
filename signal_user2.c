#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

static void signal_handler(int signo)
{
	if(signo==SIGUSR2)
	{
		printf("SIGUSR2 is handled\n");
	}
}
int main(int argc, char *argv[])
{
	int i=0;
	printf("this proc from exec of child %d\n",getpid());
	for(i=0;i<argc;i++)
	{
		printf("%s ",argv[1]);
	}
	printf("\n");
	if(signal(SIGUSR2, signal_handler)==SIG_ERR)
	{
		printf("signal usr2 was not handled correctly\n");
		exit(EXIT_FAILURE);
	}
	sleep(5);
	printf("child sends user1 signal to parent\n");
	kill(getppid(),SIGUSR1);
	sleep(10);
	printf("caca\n");
}