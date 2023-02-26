// Program Number : 24
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates an orphan process

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    int pids[2];
    int main_parent = getpid();

    //2 forks for 3 child processes and 1 parent
    for(int i=0;i<2;i++){
        pids[i] = fork();
    }
    //this checks if this is the process that spawns the other children
    if(getpid() == main_parent){
        printf("Inside parent, pid = %d\n", getpid());
        printf("Waiting for child with pid = %d\n", pids[0]);
        
        int wstatus;
        int w = waitpid(pids[0], &wstatus, 0);
        printf("Done waiting.\n");
    }else{
        printf("Inside child, going to sleep for 5s\n");
        sleep(5);
    }
    return 0;
}