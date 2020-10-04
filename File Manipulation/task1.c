#include <sys/types.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{

	char inputFileName[20];
	char outputFileName[20];
	
	printf("Please Enter the Input File Name \n");
	scanf("%s",inputFileName);
	printf("Please Enter the Output File Name \n");
	scanf("%s",outputFileName);
	FILE* fp1;
	FILE* fp2;

	if((fp1 = fopen(inputFileName,"r")) != NULL) 
	{
    	// this means input file exists file exists
		fp2 = fopen(outputFileName, "w");

		char newChar = '\0';
		printf("File content are \n");
		while (newChar != EOF)
		{
			newChar = fgetc(fp1);
			printf("%c",newChar);
			fputc(newChar, fp2);
		}
		printf("\n");
		fclose(fp1);
		fclose(fp2);

	} 
	else 
	{
    	// file doesn't exist
	  	printf("Input file does not exists");
		exit(0);
	}



	

	return 0;

}