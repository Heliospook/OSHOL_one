// Program Number : 16b
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Implements write lock

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

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    
    int fd = open(filename, O_RDWR | O_CREAT);
    int ret = fcntl(fd, F_SETLK, &lock);
    printf("Locked for 10 seconds\n");
    sleep(10);
    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLK, &lock);
    printf("File unlocked.\n");
    
	return 0;
}