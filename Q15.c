// Program Number : 15
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Prints the values of all the environment variables

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(){
	extern char **__environ;

    int i=0;
    while(__environ[i]){
        printf("%s\n", __environ[i++]);
    }
    
	return 0;
}
