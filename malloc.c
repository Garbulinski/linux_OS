#include <stdio.h>
#include <stdlib.h>

int main(void )
{
	int *p=NULL;
	int count=0;

	p=(int *)malloc(10*sizeof(int));
	if(p == NULL)
	{
		printf("allocation was NOT succesfull\n");
	}

	for(count=0;count<10;count++)
	{
		p[count]=count;
	}
	for(count=0;count<10;count++)
	{
		printf("p[%d] %d\n", count,p[count]);
	}

	p=(int *)realloc(p,15*sizeof(int));
	for(count=10;count<15;count++)
	{
		p[count]=count;
	}
	for(count=10;count<15;count++)
	{
		printf("p[%d] %d\n", count,p[count]);
	}
	return 0;
}