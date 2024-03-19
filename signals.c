#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
static void signal_hanler(int signo)
{
	if(signo==SIGINT)
	{
		printf("singal interrupt was recieved\n");
		// exit(EXIT_SUCCESS);
	}
	if(signo==SIGTERM)
	{
		printf("singal TERM was recieved\n");
		exit(EXIT_SUCCESS);
	}
}
int main(void )
{
	printf("this process has pid %d\n", getpid());

	if(signal(SIGINT, signal_hanler)==SIG_ERR){
		printf("signal interuppt was not handeled correctly\n");
		perror("ERROR: ");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGTERM, signal_hanler)==SIG_ERR){
		printf("signal term was not handeled correctly\n");
		perror("ERROR: ");
		exit(EXIT_FAILURE);
	}
	if(signal(SIGSEGV , SIG_IGN)==SIG_ERR){
		printf("signal secv was not handeled correctly\n");
		perror("ERROR: ");
		exit(EXIT_FAILURE);
	}
	while(1);
}