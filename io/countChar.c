#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	//check command line.
	if (argc != 2)
	{
		fprintf(stderr, "Command lines should be 2. \n");
		exit(1);
	}
	
	//open file.
	FILE *fp;
	if ((fp = fopen("words.txt", "r")) == NULL)
	{
		fprintf(stderr, "Can not open file.\n");
		exit(1);
	}
	
	//read file and count characters.
	char ch;
	int count = 0;
	while((ch = getc(fp)) != EOF)
	{
		count++;
		putchar(ch);
	}
	putchar('\n');
	
	//print info.
	fclose(fp);
	fprintf(stdout, "%s , count = %d\n", argv[1], count);
	return 0;
}






