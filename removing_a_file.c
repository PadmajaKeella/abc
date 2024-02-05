#include<stdio.h>
void main()
{
	int status;
	char fname[20];
	printf("enter the file name to remove");
	scanf("%s",fname);
	status=remove(fname);
	if(status==0)
	{
		printf("file is %s is removed succesfully",fname);
	}
	else
	{
		printf("unable to remove file %s",fname);
	}
}
