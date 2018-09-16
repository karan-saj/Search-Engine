#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#define HASH_SIZE 100
#define URL_LENGTH 100
#define SEED_URL "https://www.chitkara.edu.in"
#define MAX_URL_PER_PAGE 10
#define INTERVAL_TIME 10
#define CHECK_MALLOC(s) if ((s) == NULL) { \
printf("memory allocation failed in %s: line%d", _FILE, __LINE_); \
perror(":"); \
exit(-1); \
}
#define SET_MEM(start,size) memset(start,0,size)

struct URL	// Structure for URL
{
	char *c;
	int depth;
};

struct node	// Structure for node pointing to UR:
{
	struct URL u;
	int isVisited;
	struct node *next;
};

void printArguments(int argc, char *argv[])	// Print arguments provided by the user
{
	int i,j;
    printf("----------------------------------------------------------------------------------------------\n");
    for (i = 1; i < argc; i++)
    {
        for(j = 0; *(*(argv + i)+j) != '\0'; j++)
        {
            printf("%c", *(*(argv + i)+j) );
        }
        printf("\n");
    }
    printf("----------------------------------------------------------------------------------------------\n");
}

void testURL(char *url)	// Test if URL is valid or not
{
    if(strcmp(url,SEED_URL) != 0 )
    {
        printf("----------------------\n");
        printf("User Enter Invalid URL\n");
        printf("----------------------\n");
    }
    else
    {
        char ch[100] = "wget --spider ";
        strcat(ch, url);	// ch = "wget --spider https://www.xyz.com"
        if(!system(ch))	// Test if link is up and running
        {
            printf("------------------------------------------\n");
            printf("%s is a Valid URL\n", url);
            printf("------------------------------------------\n");
        }
        else
        {
            printf("---------------------\n");
            printf("%s is a not Valid URL\n", url);
            printf("---------------------\n");
        }
    }
}

void testDepth(char *depth)	// Test if directory path provided is valid or not
{
	int n;
	n=*depth-'\0';
    if(n<1 )
    {
        printf("------------------------\n");
        printf("User Enter Invalid Depth\n");
        printf("------------------------\n");
    }
}

int testArguments(int argc, char *argv[])	// Test if arguments provided by user are valid or not
{
    if(argc != 4)
    {
        printf("-------------------------------------\n");
        printf("User Enter Invalid Number Of Arguments\n");
        printf("-------------------------------------\n");
        return 0;
    }
    testURL(argv[1]);	// Test for URL
    testDepth(argv[2]);	// Test for depth
    testDir(argv[3]);	// Test for directory path provided
    return 1;
}

void getpage(char *url)	// Get the page from provided url
{
    char urlbuffer[1000] = {0};
    strcat(urlbuffer, "wget -O ");
//    strcat(urlbuffer, "/home/karan/Desktop/Projects/Crawler/data/temp.txt ");	// direct path
		strcat(urlbuffer, "./temp.txt ");	// Relative path
    strcat(urlbuffer, url);
    system(urlbuffer);
}

char *getPageContent()	// Get page content from temporary file
{
    char c;
    int i = 0;
//    FILE *fptr = fopen("/home/karan/Desktop/Projects/Crawler/data/temp.txt","r");	// Direct path
		FILE *fptr = fopen("./temp.txt","r");	// Relative path
		while (!feof(fptr))
    {
        c = getc(fptr);
        i++;
    }
    char *str = (char *) malloc(sizeof(char) * i);
    i = 0;
    rewind(fptr);
    while (!feof(fptr))
    {
        c = getc(fptr);
        str[i++] = c ;
    }
    str[i-1] = '\0';
    return str;
}

int main(int argc, char* argv[])
{
	if(argc!=4)
	{
		printf("\nCMD input is not complete");
	}
	return 0;
}
