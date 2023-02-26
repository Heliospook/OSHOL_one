// Program Number : 6
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Takes input from STDIN and outputs the same to STDOUT using only system calls

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(){
	char buffer[30];
    char message[] = "Enter some text :\n";
    write(1, message, sizeof(message));
    read(0, buffer, sizeof(buffer));
    write(1, buffer, strlen(buffer));
}
