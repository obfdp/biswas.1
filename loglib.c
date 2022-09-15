#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "log.h"
#define TRAV_INIT_SIZE 8

typedef struct list_struct {
	data_t item;
	struct list_struct *next;
} list_t;

static list_t endlist;
static list_t *headptr = NULL;
static list_t *tailptr = NULL;
static list_t **travptrs = NULL;
static int travptrs_size = 0;

time_t current_time;
struct tm * time_info;
char timeString[9];

int addmsg(data_t data) { /* allocate node for data and add to end of list */
	list_t *newnode;
 	int nodesize;
 	nodesize = sizeof(list_t) + strlen(data.string) + 1;
 	if ((newnode = (list_t *)(malloc(nodesize))) == NULL) /* couldn't add node */
 	return -1;

	time(&current_time);
	time_info = localtime(&current_time);

	strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
	newnode->item.time = puts(timeString);
	newnode->item.string = (char *)newnode + sizeof(list_t);
	
	strcpy(newnode->item.string, data.string);
	newnode->next = NULL;
	
	if (headptr == NULL)
		headptr = newnode;
	else
		tailptr->next = newnode;
		tailptr = newnode;
	return 0;
}

void clearlog() { /* free memory allocated */
	
}

char * getlog(){
	char ch;

	FILE *fp;
	fp = fopen("message.log", "r"); // read mode

	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("The contents of %s file are:\n", file_name);

	while((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);
}

int savelog ( char * filename )
{
  FILE *fptr;
  fptr = fopen("filename","w");
  if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
  fprintf(fptr,"%s",addmsg());
  fclose(fptr);
}

