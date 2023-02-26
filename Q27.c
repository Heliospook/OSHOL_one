// Program Number : 27
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Executes ls -Rl using the following system calls : execl, execlp, execle, execv, execvp

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(){

    int option;
    printf("Choose one of the commands: \n1)execl\n2)execlp\n3)execle\n4)execv\n5)execvp\n");
    scanf("%d", &option);
    
    //spawning a child process to run the new program
    int pid = fork();
    if(!pid){
        char *args1[] = {
            "/bin/ls",
            "-Rl",
            NULL
        }; 
        char *args2[] = {
            "ls",
            "-Rl",
            NULL
        };
        char *envargs[] = {
            NULL
        };

        switch(option){
            case 1:
                execl("/bin/ls", "/bin/ls", "-Rl", NULL);
                break;
            case 2:
                execlp("ls", "ls", "-Rl", NULL);
                break;
            case 3:
                execle("/bin/ls", "/bin/ls", "-Rl", NULL, envargs);
                break;
            case 4:
                execv("/bin/ls", args1);
                break;
            case 5:
                execvp("ls", args2);
                break;
        }
    }else{
        waitpid(pid, 0, 0);
    }
    return 0;
}