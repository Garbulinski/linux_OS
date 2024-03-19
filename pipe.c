#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd[2];

	char buff[50];
	char data[100];

	if(pipe(fd)==-1)
	{
		printf("pipe creation failed\n");
		exit(EXIT_FAILURE);
	}

	strcpy(buff,"This data will be read from pipe\n");
	write(fd[1],buff,strlen(buff));

	read(fd[0],data,5);
	printf("data read was %s\n",data);

	read(fd[0],data,5);
	printf("data read was %s\n",data);

	read(fd[0],data,5);
	printf("data read was %s\n",data);

	read(fd[0],data,17);
	printf("data read was %s\n",data);
}