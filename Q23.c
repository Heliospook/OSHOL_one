// Program Number : 23
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates a zombie state of the running program

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
  
int main()
{
    int i;
    int pid = fork();
  
    if (pid == 0)
    {   
        printf("Child pid = %d\n", getpid());
        exit(0);
    }
    else
    {
        printf("Parent pid = %d\n", getpid());
        sleep(30);
    }
}