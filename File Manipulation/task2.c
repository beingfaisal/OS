#include <sys/types.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main()
{

	char inputFileName[20];
	char outputFileName[20];
	
	printf("Please Enter the Input File Name \n");
	scanf("%s",inputFileName);
	printf("Please Enter the Output File Name \n");
	scanf("%s",outputFileName);
    int fd1,fd2;
    fd1 = open(inputFileName,O_RDONLY);


	if(fd1 != -1) 
	{
    	// this means input file exists file exists
		fd2 = open(outputFileName,O_WRONLY | O_CREAT);
     
		char newChar[10];
		size_t checker;
		//reading a single char and writing the single char
		checker = read(fd1,newChar,1);
		printf("File content are \n");
		while (checker > 0)
		{
			if(write(fd2,newChar,1) > 0);
				printf("%s",newChar);
			checker = read(fd1,newChar,1);
		}
		printf("\n");
		close(fd1);
		close(fd2);
	} 
	else 
	{
    	// file doesn't exist
		printf("Input file does not exists");
		exit(0);
	}
	return 0;

}