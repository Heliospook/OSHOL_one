// Program Number : 21
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Calls fork and prints parent and child process ids


#include <unistd.h>
#include <stdio.h>

int main(){
    int ret = fork();
    if(ret == -1){
        printf("Fork failed.");
    }else if(ret == 0){
        printf("Child process id : %d\n", getpid());
    }else{
        printf("Parent process id : %d\n", getpid());
    }
    return 0;
}