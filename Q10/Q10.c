// Program Number : 10
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Opens a file with O_RDWR flag, writes 10 bytes, moves file pointer by 10 bytes, and writes 10 bytes again 

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

    int fd = open(filename, O_APPEND | O_CREAT);

    write(fd, "Some random message", 10);
    off_t ret = lseek(fd, 10, SEEK_CUR);
    printf("Lseek returned : %ld\n", ret);
    write(fd, "Some random message", 10);
	return 0;
}