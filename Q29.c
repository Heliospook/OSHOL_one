// Program Number : 29
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Gets the scheduling policy and modifies it

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sched.h>
  
int main()
{
    printf("Current scheduling policy : %d\n", sched_getscheduler(getpid()));

    printf("Setting the scheduling policy to Round Robin.\n");

    struct sched_param param;
    param.sched_priority = 70;
    

    int ret = sched_setscheduler(getpid(), SCHED_RR, &param);
    perror("sched_setscheduler : ");

    printf("Current scheduling policy : %d\n", sched_getscheduler(getpid()));
    return 0;
}