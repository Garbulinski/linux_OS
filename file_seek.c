#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main( void)
{
	int fd;
	int sz;

	char buf[100];

	fd = open("seek_out.txt", O_RDWR | O_APPEND);
	if(fd==-1)
	{
		printf("file was not open correctly\n");
	}

	sz = lseek(fd,0,SEEK_SET);
	printf("current file position is %d\n",sz);

	sz = lseek(fd,2,SEEK_SET);
	printf("current file position is %d\n",sz);

	sz = lseek(fd,6,SEEK_CUR);
	printf("current file position is %d\n",sz);

	sz=read(fd,buf,10);
	buf[sz]='\n';
	printf("text that was read from file is %s", buf);

	sz=lseek(fd,4,SEEK_END);
	strcpy(buf,"appended text is this\n");
	sz=write(fd,buf,strlen(buf));


	return 0;
}