// Program Number : 1
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Creates softlink, hardlink and fifo files

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(){
	char filename[50], linkname[50];
	int option, ret;

	printf("Select : 1) softlink 2) hardlink 3) fifo\n");
	scanf("%d", &option);
	switch(option){
		case 1:
			printf("Enter filename :\n");
			scanf("%s", filename);
			printf("Enter soft link name :\n");
			scanf("%s", linkname);
			ret = symlink(filename, linkname);
			if(ret){
				printf("Link creation failed\n");
			}else printf("Soft link created\n");
			break;
		case 2:
			printf("Enter filename :\n");
			scanf("%s", filename);
			printf("Enter hard link name :\n");
			scanf("%s", linkname);
			ret = link(filename, linkname);
			if(ret){
				printf("Link creation failed\n");
			}else printf("Hard link created\n");
			break;
		case 3:
			printf("Enter name of pipe :\n");
			scanf("%s", linkname);
			mode_t mode = __S_IFIFO | 0777;
			ret = mknod(linkname, mode, 0);
			if(ret){
				printf("Pipe creation failed\n");
			}else printf("Pipe created\n");
			break;
	}
	return 0;
}
