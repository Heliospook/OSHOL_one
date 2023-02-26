// Program Number : 13
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Waits for STDIN for 10s and then verifies whether data is available or not

#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    printf("You have 10 seconds to enter data.\n");
    
    struct timeval period = {
        10,
        0
    };
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    int ret = select(1, &readfds, NULL, NULL, &period);
    if(ret == -1){
        printf("Error in using select.\n");
    }else if(ret){
        printf("Some data was entered.\n");
    }
    else{
        printf("No data entered before timeout.\n");
    }
	return 0;
}