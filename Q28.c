// Program Number : 28
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates a zombie state of the running program

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sched.h>
  
int main()
{
    printf("Maximum priority : %d\n", sched_get_priority_max(SCHED_RR));

    printf("Minimum priority : %d\n", sched_get_priority_min(SCHED_RR));

    return 0;
}