#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    int x=fork();
    if(x<0){
        printf("failed to create child process\n");
        return 0;
    }
    else if(x==0){
        printf("child process in executing\n");
        return 0;
    }
    else{
        printf("parent process is executing\n");
        return 0;
    }
    return 0;
}