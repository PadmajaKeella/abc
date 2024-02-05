#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fptr1,*fptr2;
	char ch,fname1[20],fname2[20];
	printf("enter the source file");
	scanf("%s",fname1);
	fptr1=fopen(fname1,"r");
	if(fptr1==NULL)
	{
		printf("file not found");
		exit(1);
	}
	printf("enter the name of new file");
	scanf("%s",fname2);
	fptr2=fopen(fname2,"w");
	if (fptr2==NULL)
	{
		printf("file not found");
		fclose(fptr1);
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fptr1);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch,fptr2);
		}
	}
	printf("the file %s copied succesfully to file %s\n\n",fname1,fname2);
	fclose(fptr1);
	fclose(fptr2);
	
}
