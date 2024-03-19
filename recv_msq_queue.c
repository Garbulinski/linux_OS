#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	mqd_t msg_queue;
	char *recivied_data;
	struct mq_attr atr;
	size_t len;
	msg_queue=mq_open(argv[1],O_RDONLY | O_CREAT,0660, NULL);
	if(msg_queue==-1)
	{
		printf("msgq was not open correctly\n");
		exit(EXIT_FAILURE);
	}

	if(mq_getattr(msg_queue,&atr)==-1)
	{
		printf("atributes were not recieved correctly\n");
		exit(EXIT_FAILURE);
	}
	len=(size_t)atr.mq_msgsize;
	recivied_data=calloc(sizeof(char), len);
	if(recivied_data==NULL)
	{
		printf("calloc did not work\n");
		exit(EXIT_FAILURE);
	}
	if(mq_receive(msg_queue,recivied_data,len,0)!=-1)
	{
		printf("the recieved data was %s\n",recivied_data);
	}
	mq_close(msg_queue);
}