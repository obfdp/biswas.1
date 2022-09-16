#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "log.h"

typedef struct list_struct {
	data_t item;
	struct list_struct *next;
} list_t;

int addmsg(const char type, const char * msg) {
	return 0;
}

void clearlog(){

}

char  * getlog(){
	
}

/*int savelog(char *  filename){
	return 0;
}*/


