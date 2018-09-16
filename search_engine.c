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


int main(int argc, char* argv[])
{
	if(argc!=4)
	{
		printf("\nCMD input is not complete");
	}
	return 0;
}
