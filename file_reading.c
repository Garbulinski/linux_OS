#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main( void)
{
	int fd;
	int sz;

	char buf[20]={0};
	fd = open("input.txt",O_RDONLY);

	sz= read(fd,buf, 10);
	printf("call 1 from fd %d size %d was read\n", fd, sz);
	buf[sz]='\n';
	printf("characters read are %s\n",buf);

	sz= read(fd,buf, 11);
	printf("call 2 from fd %d size %d was read\n", fd, sz);
	buf[sz]='\n';
	printf("characters read are %s\n",buf);

	sz= read(fd,buf, 10);
	printf("call 3 from fd %d size %d was read\n", fd, sz);
	if(sz==0)
	{
		perror("ERROR");
	}
	return 0;

}