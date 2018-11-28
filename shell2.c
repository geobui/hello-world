/*
 * sh1.c: sample version 1 of a UNIX command shell/interpreter.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char line[256];
    char prompt[] = "SimpleShell: Enter command or exit % ";

    /* spit out the prompt */
    printf("%s", prompt );


    /* Try getting input. If error or EOF, exit */
while( fgets(line, sizeof line, stdin) != NULL ) 
    {
	/* fgets leaves '\n' in input buffer. ditch it */
	line[strlen(line)-1] = '\0';

    if(strcmp(line,"exit") == 0){
        break;
    } else{
		
		pid_t pid;
		pid = fork();
	  if(pid < 0) {
		perror("fork() error");
		exit(-1);
	  }	  
	  else if (pid != 0) {
		wait(NULL);
	  }
	  else {
		fork();
		execlp(line, line, (char *)NULL);	  
	  }
	  //fork();
	  //system( line );

    }
	printf("%s", prompt );

	}
    return 0;
}