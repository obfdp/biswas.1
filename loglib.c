#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "log.h"

typedef struct list_struct {
	data_t item;
	struct list_struct *next;
} list_t;

static list_t endlist;
static list_t *headptr = NULL;
static list_t *tailptr = NULL;
static list_t **travptrs = NULL;
static int travptrs_size = 0;
static struct logger_t log_global_set;


time_t current_time;
struct tm * time_info;
char timeString[9];

int addmsg(const char type, const char * msg) { /* allocate node for message and add to end of list */
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

void clearlog( string **store) { /* releases all the storage that has been allocated for the logged message and empties the list of logged messages */
	free(store);
 	return 0;
}

char * getlog(){
	char ch;

	FILE *fp;
	string msg;
	string *m
	string **store
	fp = fopen("message.log", "r"); // read mode

	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(file)) != EOF)
    {
        msg = ch;
    }
    m = &msg;


   if(!m){
   perror("Error occured allocating memory");
   exit(-1);
   }

	store = malloc(sizeof(m));

	printf("The contents of %s file are:\n", "message.log");

	while((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);



}

int savelog ( char * filename ) //savelog function saves the logged message to a disk file.
{
    struct tm* current_tm;
    time_t time_now;

    time(&time_now);
    current_tm = localtime(&time_now);



    log_global_set.out_file = fopen(filename, "w"); //write mode

    if (log_global_set.out_file == NULL) {
        log_error("Failed to open file %s error %s", filename, strerror(errno));
        return -1;
    }

    int result = fprintf(log_global_set.out_file,
            "%s: %02i:%02i:%02i\n"
                , message
                , current_tm->tm_hour
                , current_tm->tm_min
                , current_tm->tm_sec);

    if (result == -1) {
        printf("Unable to write to log file!");
        return -1;
    }

    fflush(log_global_set.out_file);
    return 0;
}





