#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40

int main(int argc, char *argv[])
{
	char name[SIZE];
	//check command line.
	if (argc != 2)
	{
		fprintf(stderr, "Command lines should be 2. \n");
		exit(1);
	}
	
	//open in stream.
	FILE *in;
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can not open file.\n");
		exit(1);
	}
	
	//open out stream.
	FILE *out;
	strcpy(name, argv[1]);
	strcat(name, ".red");
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can write to file.\n");
		exit(1);
	}
	
	//read in and compress to out.
	char ch;
	int count = 0;
	while((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
		{
			putchar(ch);
			putc(ch, out);
		}
	}
	putchar('\n');
	
	//close io stream.
	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Can not close io.");
		exit(1);
	}
	return 0;
}






