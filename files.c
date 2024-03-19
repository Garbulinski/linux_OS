#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(void )
{
	int fd;
	fd = open("startup",O_RDONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IROTH );

	if(fd==-1)
	{
		printf("file was not created because %d\n",errno);
		perror("ERROR:");
	}
	else
	{
		printf("file was created succesfully\n");
	}
}