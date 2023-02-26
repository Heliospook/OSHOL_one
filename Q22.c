// Program Number : 22
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Opens a file, calls fork, writes to the file using both the parent and child processes

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
    char filename[50];
    printf("Enter filename :\n");
    scanf("%s", filename);

    int fd = open(filename, O_WRONLY | O_CREAT, 0777);
    if(fd == -1){
        printf("Failed to open file.");
        return 0;
    }

    int ret = fork();
    if(ret == -1){
        printf("Fork failed.");
    }else if(ret == 0){
        write(fd, "Writing into the file from the child process.\n", 46);
    }else{
        write(fd, "I am the parent process, fear me you puny mortal.\n", 51);
    }

    close(fd);
    return 0;
}