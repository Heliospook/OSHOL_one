// Program Number : 17
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Opens file, implements write lock, reads ticket number, increments number and print new ticket number

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd = open("ticket.txt", O_RDWR | O_EXCL, 0777);
	
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    fcntl(fd, F_SETLKW, &lock);

    int ticket_number;
    read(fd, &ticket_number, sizeof(ticket_number));
    ticket_number++;

    printf("New ticket number : %d\n", ticket_number);

    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket_number, sizeof(ticket_number));

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    
	return 0;
}