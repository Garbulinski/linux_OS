#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
	int fd, count;

	char buf[100];

	fd = open("output.txt", O_WRONLY | O_APPEND);/// daca scot append o sa ia O_TRUNK ca si parametru default
	if(fd<0)
	{
		printf("file was not open\n");
	}
	strcpy(buf,"This message was appended to file\n");

	count = write(fd,buf,strlen(buf));

	printf("size of buff %d\n",(int)strlen(buf));
	if(count!=0)
	{
		printf("writing was made succesfully %d\n", count);
	}
}