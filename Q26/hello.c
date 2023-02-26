// Program Number : 26
// Name : Subhajeet Lahiri
// Register Number : IMT2021022 
// Date : 24/2/23
// Description : Hello world program which accepts arguments


#include <stdio.h>

int main(int argc, char *argv[]){

    //Checking if there are arguments available
    if(argc > 1){
        printf("Hello");
        for(int i=1;i<argc;i++){
            printf(" %s", argv[i]);
        }
        printf("!\n");
    }else{
        printf("Hello world!\n");
    }
}