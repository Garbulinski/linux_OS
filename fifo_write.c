#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
int main(void )
{
	int fd;

	char *fifo_path="/tmp/fifo_fd";
	char arg[100];

	printf("code breaks before fifo\n");
	mkfifo(fifo_path,0660);
	fd=open(fifo_path,O_WRONLY);
	if(fd==-1)
	{
		printf("file was not open corectly\n");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		printf("enter a string\n");
		fgets(arg,80,stdin);

		write(fd,arg,strlen(arg));
	}
	close(fd);
	exit(1);
}