// Program Number : 9
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Prints the following info about a file :
// a. inode
// b. number of hard links
// c. uid
// d. gid
// e. size
// f. block size
// g. number of blocks
// h. time of last access
// i. time of last modification
// j. time of last change

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

    struct stat info;
    int ret = stat(filename, &info);
    if(ret){
        printf("Error. Couldn't retrieve details.");
        return -1;
    }

    printf("Inode number : %ld\n", info.st_ino);
    printf("Number of hard links : %ld\n", info.st_nlink);
    printf("UID : %d\n", info.st_uid);
    printf("GID : %d\n", info.st_gid);
    printf("Size : %ld\n", info.st_size);
    printf("Block size : %ld\n", info.st_blksize);
    printf("Number of blocks : %ld\n", info.st_blocks);
    printf("Time of last access: %ld\n", info.st_atime);
    printf("Time of last modification: %ld\n", info.st_mtime);
    printf("Time of last change: %ld\n", info.st_ctime);
    
	return 0;
}
