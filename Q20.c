// Program Number : 20
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Check priority and update priority using nice call

#include <unistd.h>
#include <stdio.h>

int main(){
    int priority = nice(0);
    printf("Current priority : %d\n", priority);

    int new_priority;
    printf("Enter new priority : \n");
    scanf("%d", &new_priority);

    nice(new_priority - priority);
    priority = nice(0);
    printf("Current priority : %d\n", priority);

    return 0;
}