// Program Number : 11b
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Opens a file, duplicates the file descriptor and appends to the file with both the descriptors, using dup2

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

    int fd1 = dup2(fd, 10);
    write(fd, "Something wrtiten to the original file descriptor\n", 51);
    write(fd1, "Now we are using the duplicate file descriptor(using dup2)\n",60);

    close(fd);
    close(fd1);
    
	return 0;
}