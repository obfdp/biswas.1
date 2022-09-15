#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char * argv[]) {
  int opt;
  
  char *filename = "message.log";

//getopt implementation to parse options and receive the command parameters

while ((opt = getopt(argc, argv, "h")) != -1) {
  switch (opt) {
  case 't':
    n = atoi(optarg);
    fprintf(stderr, "\n\nEnter delay time: %s \n", optarg);
    perror("driver: Error: No argument value specified for time delay!");
    break;
  case ':':
    fprintf(stderr, "option needs a value \n");
    perror("driver: Error: No value given for options!");
    break;
  case '?':
    fprintf(stderr, "unknown option: %c \n", optopt);
    if(optopt == 't'){
	   fprintf (stderr, "Option -%c requires an argument.\n", optopt);
	   perror("driver: Error: No argument value specified for time delay!");
	 }
    else if (isprint (optopt)){
	   fprintf (stderr, "Unknown option `-%c'.\n", optopt);
	   perror("driver: Error: Incorrect argument given!");
	 }
    else {
	   fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
	   perror("driver: Error: Unknown argument given!");
	   return 1;
	}
      break;
    case 'h':
      fprintf(stderr, "\n\nSolution can be invoked using the following command: \n ./driver [-h] [-t secs] [logfile] < textfile \n\h help \n\t sleeptime Time to delay [default 3s] \n");
      break;;
    }
  }



