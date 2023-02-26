// Program Number : 12
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Gives the opening mode of a file, using fcntl

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

    int fd = open(filename, O_RDWR | O_CREAT | O_APPEND);

    int mode = fcntl(fd, F_GETFL);
    printf("Opening mode : %d\n", mode);
    
    close(fd);
    
	return 0;
}