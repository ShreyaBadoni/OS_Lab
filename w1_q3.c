#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    int x=fork();
    if(x<0){
        printf("process failed\n");
        return 0;
    }
    if(x==0){
        execlp("ls","ls","-l",(char*)NULL);
        printf("first child process ");
        exit(0);
    }
    else{
        wait(NULL);
        printf("first child completed its work\n");
        int y=fork();
        if(y<0){
            printf("process failed\n");
            return 0;
        }
        else if(y==0){
            printf("second child process\n");
            sleep(5);
            printf("second child process done\n");
            exit(0);
        }
        else{
            printf("parent process done executing \n");
            exit(0);
        }
    }
    return 0;
}