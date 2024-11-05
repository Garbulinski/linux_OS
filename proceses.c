/*
	in linux the first procces created is the swaper proces	
	second process is init - becomes the parent process of any orphan process
	the states of o process- created,runinng , ready to run(in swap or main memory), sleep(in swap or main memory), blocked(in swap or main memory), terminated

	ps ef commanda pentru a vedea toate procese in executare
*/
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("this process has pid %d\n",getpid());
	printf("this proccess has parent id %d\n",getppid());

	sleep(10);
	printf("the proces was terminated\n");
}