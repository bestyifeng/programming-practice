#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define ANSWER "GRANT"
#define SIZE 40


char menu();
void printAll(int m, char strs[m][SIZE]);
void printByAscii(int m, char strs[m][SIZE]);
void printByLength(int m, char strs[m][SIZE]);
void printByFirstWord(int m, char strs[m][SIZE]);
void swap_string(char *str1, char *str2);
void swap_int(int *a, int *b);
void copyArray(int m, char target[m][SIZE], char source[m][SIZE]);
void getFirstWordLength(int m, int length[m], char strs[m][SIZE]);

int main(void)
{
	char strs[10][SIZE];
	char str[SIZE];
	
	printf("Give me strings, no more than 10 and \'&\' to stop.\n");
	int count = 0;
	bool stop = false;
	while (stop != true && count < 10)
	{
		gets(strs[count]);
		
		printf("%s\n", strs[count]);
		
		if(strs[count][0] != '&')
		{
			count++;
		}
		else
		{
			stop = true;
		}
	}
	printf("Over!\n");
	
	if(count < 0)
		printf("No word.Stop!\n");
	else
	{
		int order = menu();
		while(order != '5')
		{
			if(order == '1')
			{
				printAll(count, strs);
			}
			else if(order == '2')
			{
				printByAscii(count, strs);
			}
			else if (order == '3')
			{
				printByLength(count, strs);
			}
			else if (order == '4')
			{
				printByFirstWord(count, strs);
			}
			else
			{
				printf("Please give me a integer between 1-5.\n");
			}
			order = menu();
		}
	}
}

char menu()
{
	printf("Give me a value: 1-5:\n");
	printf("1) printf all the strings.\n");
	printf("2) print all the strings ordered by ascii.\n");
	printf("3) print all the strings ordered by length.\n");
	printf("4) print all the strings ordered by first word's leng\n");
	printf("5) print 5 to quit.\n");
	
	char ch = getchar();
	
	//clear input.
	char clear;
	while(clear = getchar() != '\n')
	{
		continue;
	}
	return ch;
}



void printAll(int m, char strs[m][SIZE])
{
	for(int i=0; i<m; i++)
	{
		puts(strs[i]);
	}
}

void printByAscii(int m, char strs[m][SIZE])
{
	//copy strings.
	char copy_strs[m][SIZE];
	copyArray(m, copy_strs, strs);
	
	//order by ascii.
	for(int i=0; i<m-1; i++)
	{
		int min = i;
		for(int j=i+1; j<m; j++)
		{
			if (copy_strs[j][0] < copy_strs[i][0])
			{
				min = j;
			}
		}
		
		swap_string(copy_strs[i], copy_strs[min]);
	}
	
	//print all.
	printAll(m, copy_strs);
}

void swap_int(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void swap_string(char *str1, char *str2)
{
	char temp;
	for(int i=0; i<SIZE; i++)
	{
		temp = str2[i];
		str2[i] = str1[i];
		str1[i] = temp;
	}
}

void copyArray(int m, char target[m][SIZE], char source[m][SIZE])
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			target[i][j] = source[i][j];
		}
	}
}

void printByLength(int m, char strs[m][SIZE])
{
	//store string length in length[].
	int length[m];
	for(int i=0; i<m; i++)
	{
		length[i] = strlen(strs[i]);
	}
	
	//copy strings.
	char copy_strs[m][SIZE];
	copyArray(m, copy_strs, strs);
	
	//swap by length;
	for(int i=0; i<m-1; i++)
	{
		int min = length[i];
		int index = i;
		for(int j=i+1; j<m; j++)
		{
			if(length[j] < min)
			{
				min = length[j];
				index = j;
			}
		}
		swap_int(&length[i], &length[index]);
		swap_string(copy_strs[i], copy_strs[index]);
	}
	
	//print all.
	printAll(m, copy_strs);
	
}

void printByFirstWord(int m, char strs[m][SIZE])
{
	// get first word length.
	int length[m];
	getFirstWordLength(m, length, strs);
	
	//copy strings.
	char copy_strs[m][SIZE];
	copyArray(m, copy_strs, strs);
	
	//swap by length;
	for(int i=0; i<m-1; i++)
	{
		int min = length[i];
		int index = i;
		for(int j=i+1; j<m; j++)
		{
			if(length[j] < min)
			{
				min = length[j];
				index = j;
			}
		}
		swap_int(&length[i], &length[index]);
		swap_string(copy_strs[i], copy_strs[index]);
	}
	
	//print all.
	printAll(m, copy_strs);
}

void getFirstWordLength(int m, int length[m], char strs[m][SIZE])
{
	int count;
	for(int i=0; i<m; i++)
	{
		count = 0;
		for (int j=0; j<SIZE; j++)
		{
			if(isalpha(strs[i][j]))
			{
				count++;
			}
			else if (count > 0)
			{
				break;
			}
		}
		length[i] = count;
	}
}











