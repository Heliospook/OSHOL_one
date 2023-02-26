// Program Number : 5
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates five new files and then goes into infinite loop

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(){
	char base[50];
    strcpy(base, "file");
    int fds[5];
    mode_t mode = 0777;

    for(int i=0;i<5;i++){
        char str[2]; sprintf(str, "%d", i);
        char filename[50];
        strcpy(filename, base); strcat(filename, str);
        fds[i] = creat(filename, mode);
    }
    printf("Files created. Going into infinite loop...");
    for(;;);
	return 0;
}
