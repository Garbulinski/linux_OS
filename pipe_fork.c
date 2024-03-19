#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	int fd[2];
	char buf[100]={};
	int child;
	ssize_t s;

	if(pipe(fd)==-1)
	{
		printf("pipe was not created correctly\n");
	}

	switch (child=fork())
	{
	case -1:
		printf("child was not created correctly\n");
		break;
	case 0:
		if(close(fd[1]==-1))
		{
			exit(-1);
		}

		for(;;)
		{
			strcpy(buf,"");
			s=read(fd[0],buf,100);
			if(s==-1)
			{
				printf("read was not made succesfully\n");
				exit(EXIT_FAILURE);
			}
			if(s==0)
			{
				printf("reaching end of file\n");
			}
			printf("data read was %s\n",buf);
			if(close(fd[0])==-1)
			{
				printf("\n child: parent closed write end\n");
				break;
			}
			// strcpy(buf,"");
			// s = read(fd[0], buf, 100);
			// if (s == -1)
			// 	exit(-1);
			// if (s == 0){
			// 	printf("\n child: parent closed write end\n");
			// 	break;
			// }
			// /* End-of-file */
			// printf("\ndata received in child process is (%s)\n",buf);
		}

		break;
	default:
		if(close(fd[0]==-1))
		{
			exit(EXIT_FAILURE);
		}

		s=write(fd[1],argv[1],strlen(argv[1]));

		sleep(2);
		
		if (close(fd[1]) == -1)
			exit(-1);
		printf("\n parent: closed write end\n");
		wait(NULL);
		exit(0);

		break;
	}
}