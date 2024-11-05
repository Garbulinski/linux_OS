#include <stdio.h>
#include <unistd.h>

int main()
{
	int child_pid; 
	
	child_pid = fork();

	if(child_pid == -1)
	{
		printf("fork failed\n");
	}
	else if(child_pid > 0)
	{
		printf("Parent created process with child id %d\n", child_pid);
	}
	else if(child_pid == 0)
	{
		printf("this printf is from child procees \n");
		printf("child process has id %d\n",getpid());
		printf("child process was created from parent with pid %d\n", getppid());
	}
}