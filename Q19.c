// Program Number : 19
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Gives the time taken to execute getpid system call using the values read from the time stamp counter

#include <unistd.h>
#include <stdio.h>

unsigned long long read_tsc()
{
    unsigned long long lo, high;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(high));                        
    return lo | (high << 32);  
}

int main(){
    unsigned long long time = read_tsc();
    int pid = getpid();
    time = read_tsc() - time;
    printf("Time taken = %lld clock ticks\n", time);
    return 0;
}