// Program Number : 18
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates three records in a file

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
    printf("Enter filename :\n");
    scanf("%s", filename);

    Record records[3] = {
        {1, 8439, "First Record"},
        {2, 9798, "Second Record"},
        {3, 3085, "Third Record"}
    };

    int fd = open(filename, O_WRONLY | O_CREAT);
    for(int i=0;i<3;i++){
        write(fd, &records[i], sizeof(Record));
    }
    printf("Written three records.\n");
    printf("Size of individual record : %ld bytes\n", sizeof(Record));

    return 0;
}