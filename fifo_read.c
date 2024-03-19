#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *fifo_path="/tmp/fifo_fd";
	char arg[80];
	int fd;

	fd=open(fifo_path,O_RDONLY);

	while(1)
	{
		read(fd,arg,80);

		printf("the data recieved from another proc was %s\n", arg);
	}
	return 0;
}