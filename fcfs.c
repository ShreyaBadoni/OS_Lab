#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct process{
    int id,at,bt,st,ct,wt,tat,rt;
}process;
int compare(const void *a,const void *b){
    process(*p1)=(process*)a;
    process(*p2)=(process*)b;
    return p1->at -p2->at;

}
int main(){
    int n;
    int ttat=0,twt=0,tbt=0;
    float atat=0.0,awt=0.0;
    float cpu_util=0.0,throughput=0.0;
    printf("enter the number of processes ");
    scanf("%d",&n);
    process p[n];
    for (int i = 0; i < n; i++) 
    {
        p[i].id = i + 1;
    }
    printf("enter arrival time for the processes ");
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].at);
    }
    printf("enter burst time of the processes ");
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].bt);
    }
    qsort(p,n,sizeof(process),compare);
    for(int i=0; i<n; i++){
        if(i==0){
            p[i].ct=p[i].at+p[i].bt;
        }
        else if(p[i-1].ct<p[i].at){
            p[i].ct=p[i].at+p[i].bt;
        }
        else{
            p[i].ct=p[i-1].ct+p[i].bt;
        }
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        p[i].rt=p[i].wt;
        ttat=p[i].tat+ttat;
        twt=p[i].wt+twt;
        tbt=p[i].bt+tbt;
    }
    
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) \
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
    printf("Total turnaround time: %d\n", ttat);
    printf("Total waiting time: %d\n", twt);
    printf("Average turnaround time: %.2f\n", (float)ttat/n);
    printf("Average waiting time: %.2f\n", (float)twt/n);
    int totalbt = 0;
    for (int i = 0; i < n; i++) 
    {
        totalbt += p[i].bt;
    }
    printf("Total CPU utilization = %d%%\n", (totalbt * 100) / p[n - 1].ct);
    printf("Total throughput = %d%%\n", (n * 100) / p[n - 1].ct);
    return 0;
}

