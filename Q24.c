// Program Number : 24
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates an orphan process

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){

    int ret = fork();
    if(ret == -1){
        printf("Fork failed.");
    }else if(ret == 0){
        printf("Child going to sleep, with ppid = %d\n", getppid());
        sleep(2);
        printf("Orphan now, ppid = %d\n", getppid());
    }else{
        sleep(1);
        printf("Exiting parent.\n");
        exit(0);
    }

    return 0;
}