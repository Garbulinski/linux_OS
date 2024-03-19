#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>

int main(void)
{
	int fd;
	char *addr;
	struct stat len;

	fd=shm_open("/shared_memory",O_RDONLY,0);

	if(fd==-1)
	{
		printf("memory was not open\n");
		exit(EXIT_FAILURE);
	}

	fstat(fd,&len);
	addr=mmap(NULL,len.st_size,PROT_READ,MAP_SHARED,fd,0);

	if(addr==MAP_FAILED)
	{
		printf("memory was not mmap correctly\n");
		exit(EXIT_FAILURE);
	}

	printf("read messsage is %s\n",addr);
	return 0;
}