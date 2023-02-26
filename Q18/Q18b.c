// Program Number : 18b
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Locks specific record in a file(write lock), reads the record and waits for the user to release the lock

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "Record.h"

int main(){
    char filename[50];
    printf("Enter filename to read records from :\n");
    scanf("%s", filename);

    chmod(filename, 0777);
    int fd = open(filename, O_RDWR | O_EXCL);

    int record_number;
    printf("Select record to apply read lock on (1-3):\n");
    scanf("%d", &record_number);
    
    int record_size = sizeof(Record);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_number - 1)*record_size;
    lock.l_len = record_size;
    lock.l_pid = getpid();
    fcntl(fd, F_SETLKW, &lock);
    perror("");

    printf("Record %d locked.\n", record_number);
    
    Record record;
    lseek(fd, (record_number - 1)*record_size, SEEK_SET);
    read(fd, &record, record_size);
    printf("Record read : %d %d %s\n", record.index, record.data, record.description);

    printf("Press Enter to continue.\n");
    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);

    return 0;
}