// Program Number : 14
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Finds the type of file

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>


int main(){
	char filename[50];
    printf("Enter filename :\n");
    scanf("%s", filename);

    struct stat info;
    int ret = stat(filename, &info);
    if(ret){
        printf("Error. Couldn't retrieve details.");
        return -1;
    }

    switch (info.st_mode & __S_IFMT) {
        case __S_IFBLK:  
            printf("block device\n");            break;
        case __S_IFCHR:  
            printf("character device\n");        break;
        case __S_IFDIR:  
            printf("directory\n");               break;
        case __S_IFIFO:  
            printf("FIFO/pipe\n");               break;
        case __S_IFLNK:  
            printf("symlink\n");                 break;
        case __S_IFREG:  
            printf("regular file\n");            break;
        case __S_IFSOCK: 
            printf("socket\n");                  break;
        default:       
            printf("unknown type\n");              
            break;
    }

    
	return 0;
}