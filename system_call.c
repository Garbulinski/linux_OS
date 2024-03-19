/* demo to show the write system call */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void )
{
	size_t len;
	int msg_len = 0;
	char buf[100];

	strncpy(buf,"This is writing to screen using write() system call instead of pritnf library call\n",99);

	msg_len=strlen(buf);

	len = write(1,buf,msg_len);
	return 0;
}
