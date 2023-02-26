// Program Number : 8
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Reads a file line by line and closes it on EOF

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

    int fd = open(filename, O_RDONLY | O_EXCL);
    if(fd == -1){
        printf("File does not exist\n");
        return -1;
    }

    //to read the file character-by-character and detect \n 
    char buff[2];

    //second buffer to store the line
    char line[1000];
    strcpy(line, "");

    int line_counter = 1;
    while(read(fd, buff, 1)){
        strcat(line, buff);
        if(buff[0]=='\n'){
            printf("line %d : %s",line_counter, line);
            line_counter++;
            strcpy(line, "");
        }
    }
	return 0;
}
