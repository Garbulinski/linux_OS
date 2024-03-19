#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

static int global_data=111;

int main()
{
	// pid_t id;
	
	// printf("parent proc %d creates a child\n",getpid());
	// id=fork();
	// if(id<0)
	// {
	// 	printf("child was NOT created succsesfully\n");
	// }
	// else if(id>0)
	// {	
	// 	printf("this part of the program is executed from the parent process %d\n", getpid());
	// }
	// else if(id==0){
	// 	printf("this is child procress created by %d parent\n", getppid());
	// 	printf("id of child is %d", getpid());
	// }

	int stack_data=222;
	pid_t id;
	switch (id=fork())
	{
	case 0:
		printf("the child process is executing %d with parent %d\n",getpid(),getppid());
		global_data*=3;
		stack_data*=4;
		printf("global data %d stack_data %d in child process %d execution\n", global_data,stack_data,getpid());
		sleep(5);
		break;
	
	default:
		printf("the parent process is executing %d\n",getpid());
		printf("global data %d stack_data %d in child process %d execution\n", global_data,stack_data,getpid());
		sleep(5);
		break;
	}
	return 0;
}