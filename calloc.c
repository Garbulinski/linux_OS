#include <stdio.h>
#include <stdlib.h>

struct User
{
	int id;
	int sal;
};

int main(void)
{
	struct User *us=NULL;
	int count=0;

	us=(struct User *)calloc(10, sizeof(struct User));

	for(count=0;count<10;count++)
	{
		printf("user %d id %d\n", us[count].id, us[count].sal);
	}
	for(count=0;count<10;count++)
	{
		us[count].id=count;
		us[count].sal=count+100;
	}
	for(count=0;count<10;count++)
	{
		printf("user %d id %d\n", us[count].id, us[count].sal);
	}
	free(us);
	return 0;
}