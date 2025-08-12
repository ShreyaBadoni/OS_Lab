#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    pid_t pid= fork();
    if(pid<0){
        printf("process failed\n");
    
    }
    else if(pid==0){
        printf("child process\n");
        printf("child pid -> %d \n",getpid());
        printf("parent pid -> %d \n",getppid());
    }
    else{
        printf("parent process \n");
        printf("parent pid -> %d \n",getpid());
        printf("child pid -> %d \n",pid);
    }
    return 0;
}