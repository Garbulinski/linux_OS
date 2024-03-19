#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// extern char **environ; this varaible holds all the variables of a enviorement process
void call_param1();
int main(int argc, char **argv)
{	
	//**************** this is how to go through the enviorement list
	// char **ep;  
	// for(ep=environ;*ep!=NULL;ep++)
	// {
	// 	printf("%s\n",*ep);
	// }
	putenv("PARAM1=1024");
	printf("%s\n",getenv("PATH"));
	printf("%s\n",getenv("HOME"));
	printf("%s\n",getenv("PARAM1"));
	call_param1();
	return 0;
}

void call_param1()
{
	printf("%s\n",getenv("PARAM1"));
}