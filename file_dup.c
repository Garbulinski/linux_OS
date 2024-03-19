#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void )
{
	int fd;
	int new_fd;

	fd = open("file_dup.txt", O_RDWR | O_CREAT);
	if(fd == -1)
	{
		printf("file was not open correctly\n");
		perror("ERROR:");
	}

	new_fd = dup(fd);
	write(fd,"this text was written form fd\n", 31);
	write(new_fd,"this text was writen from new fd\n",34);
	return 0;

}	