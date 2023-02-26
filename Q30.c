// Program Number : 30
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Runs daemon process to execute ls after the duration entered by the user

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

void run_daemon()
{
    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
        printf("Daemon process id = %d\n", getpid());
        printf("To kill daemon, use kill %d\n", getpid());
        sleep(2);
        return;
    }else exit(0);
}

int main(){
    int time;
    printf("Enter time in seconds : \n");
    scanf("%d", &time);

    run_daemon();

    sleep(time);
    printf("\n");
    execlp("ls", "ls", NULL);
    return 0;
}
