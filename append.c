#include<stdio.h>
int main()
{
	FILE *fptr;
	int i,n;
	char str[100];
	char fname[100];
	char str1;
	printf("enter the file name to be append");
	scanf("%s",fname);
	fptr=fopen(fname,"a");
	printf("enter the no. of lines to be written");
	scanf("%d",&n);
	printf("the lines are:");
	for(i=0;i<n+1;i++)
	{
		fgets(str,sizeof(str1),stdin);
		fputs(str,fptr);
	}
	fclose(fptr);
	fptr=fopen(fname,"r");
	printf("the contents of file %s is :\n",fname);
	str1=fgetc(fptr);
	while(str!=EOF)
	{
		printf("%c",str1);
		str1=fgetc(fptr);
	}
	printf("\n\n");
	fclose(fptr);
	return 0;
}
