#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
int main(int argc, char *argv[])
{
	int fd;
	int len;
	int *addr;
	fd=shm_open("/shared_memory",O_RDWR|O_CREAT,0660);

	if(fd==-1)
	{
		printf("memory was not open correctly\n");
		exit(EXIT_FAILURE);
	}

	len=strlen(argv[1]);
	if(ftruncate(fd,len)==-1)
	{
		printf("memory alocation was not made correctly\n");
		exit(EXIT_FAILURE);
	}

	addr=mmap(NULL,len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if(addr==MAP_FAILED)
	{
		printf("failed to map shared memory\n");
		exit(EXIT_FAILURE);
	}
	if(close(fd)==-1)
	{
		perror("close ");
	}
	memcpy(addr,argv[1],len);
	return 0;
}

