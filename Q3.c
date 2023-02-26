// Program Number : 3
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates a file and prints the fd

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

    mode_t mode = 0777;
    int fd = creat(filename, mode);

    printf("The file descriptor value is : %d\n", fd);
	return 0;
}