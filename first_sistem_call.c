#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void )
{
	size_t len = 0;
	int msg_len = 100;
	char buf[100];

	strncpy(buf,"This is a second attempt to work for luxoft \n",99);

	len = write(1,buf, msg_len);
	return 0;
}
