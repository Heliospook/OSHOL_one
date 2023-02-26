// Program Number : 26b
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Executes an executable program while passing arguments to the same

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

    char program[50];
    char name[50] = "Subhajeet";
    printf("Enter the name of the program to execute: \n");
    scanf("%s", program);
    printf("Enter a name : \n");
    scanf("%s", name);
    //spawning a child process to run the new program
    int pid = fork();
    if(!pid){
        char *args[] = {
            program,
            name,
            NULL
        }; 
        execv(program, args);
    }else{
        waitpid(pid, 0, 0);
    }
    return 0;
}