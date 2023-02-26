// Program Number : 7
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Copies one file into another

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(){
	char source[50];
    printf("Enter source :\n");
    scanf("%s", source);
    int source_fd = open(source, O_RDONLY|O_EXCL);
    if(source_fd == -1){
        printf("Source not found.\n");
        return -1;
    }

    char dest[50];
    printf("Enter destination :\n");
    scanf("%s", dest);
    int dest_fd = open(dest, O_WRONLY|O_CREAT, 0777);
    
    //small buffer size for greater accuracy
    char buffer[1];
    while(read(source_fd, buffer, sizeof(buffer))){
        write(dest_fd, buffer, sizeof(buffer));
    }
	return 0;
}
