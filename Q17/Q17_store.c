// Program Number : 17
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Opens file, stores ticket number and exits

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
	int ticket_number;
    printf("Enter ticket number :\n");
    scanf("%d", &ticket_number);
    
    int fd = open("ticket.txt", O_WRONLY | O_CREAT, 0777);
    write(fd, &ticket_number, sizeof(ticket_number));

    close(fd);
	return 0;
}