#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <time.h>

int main(){
    FILE* log;
    const char filepath[] = "/tmp/ParentProcessStatus.log";
    log = fopen(filepath, "w");
    for(int i=0;i<10;i++){
	char childName[50];
	sprintf(childName, "LikeServer%d", i);
        if(fork() == 0){
	    int timeAlive = 0, fiveMinutes = 5;
	    clock_t start = clock();

	    //name the process and write to parent log that child created
	    fprintf(log, "%s created\n", childName);
	    fflush(log);
	    prctl(PR_SET_NAME, (unsigned long) childName);
            printf("[child] pid %d from [parent] pid %d %s\n",getpid(),getppid(), childName);

	    //children are created 1 second after the  other
	    sleep(1);

	    //keeps child alive for five minutes
	    while(timeAlive < fiveMinutes){
                clock_t timePassed = clock() - start;
	        timeAlive = (timePassed / CLOCKS_PER_SEC)/60;

	    }
	    fprintf(log, "%s ended\n", childName);
	    fflush(log);
	    exit(0);
        }
	else{
//	    printf("parent\n");
	    wait(NULL);
	}
	
    }
    fclose(log);
    return 0;
}
