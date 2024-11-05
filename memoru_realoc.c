#include <stdio.h>
#include <stdlib.h>

int main(void )
{
	int *point;
	int count = 0;

	point = (int*) malloc(10 * sizeof(int));

	if(point == NULL)
	{
		printf("memory was not allocated correctly \n");
		return -1;
	}

	for(count = 0; count < 10; count++)
	{
		point[count] = count;
	}
	for(count = 0; count < 10; count++)
	{
		printf("%d ",point[count]);
	}
	printf("\n");
	point = (int *) realloc(point, 15 * sizeof(int));

	for(count = 0; count < 15; count++)
	{
		point[count] = count;
	}
	for(count = 0; count < 15; count++)
	{
		printf("%d ",point[count]);
	}
	printf("\n");
	return 0;
}