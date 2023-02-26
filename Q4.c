// Program Number : 4
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Opens an existing file in read write mode using the O_EXCL flag

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(){
	char filename[50];
    printf("Enter filename :\n");
    scanf("%s", filename);

    int flags = O_RDWR | O_EXCL;
    int fd = open(filename, flags);

    printf("The file descriptor value is : %d\n", fd);
    if(fd == -1){
        printf("There was some error opening the file.");
    }else{
        printf("File opened successfully.\n");
        char message[30];
        strcpy(message, "Hello there.\n");
        write(fd, message, sizeof(message));
        close(fd);
    }
	return 0;
}
