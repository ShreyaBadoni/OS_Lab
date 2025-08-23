#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    FILE *f1,*f2;
    char line1[100],line2[100];
    f1=fopen("S.txt","w");
    fprintf(f1,"Name: shreya\nAge: 20\nCity: Dehradun\n");
    fclose(f1);
    f2=fopen("friend.txt","w");
    fprintf(f2,"Name: Ayushi\nAge: 20\nCity: Dehradun\n");
    fclose(f2);
    f1=fopen("S.txt","r");
    f2=fopen("friend.txt","r");
    printf("Matching lines:\n");
    while(fgets(line1,100,f1)!=NULL){
        rewind(f2);
        while(fgets(line2,100,f2)!=NULL){
            if(strcmp(line1,line2)==0){
                printf("%s",line1);
            }  }  
}
    fclose(f1);
    fclose(f2);
    return 0;
}
