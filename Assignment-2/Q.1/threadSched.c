#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BILLION 1000000000L
pthread_t ThrA, ThrB, ThrC;

void histo(double x)
{
    FILE *ptr;
    ptr = fopen("file.txt","a");
    fprintf(ptr,"%lf ",x);
    fclose(ptr);
    
}

void* countA(void *diff)
{
    struct sched_param prio;
    int* d=(int*)diff;
    prio.sched_priority=*d;
    pthread_setschedparam(ThrA,SCHED_OTHER,&prio);

    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);
    
    long long int i;
    long long int k=(long long int)pow(2,32);
    for(i=0;i<k;i++);

    clock_gettime(CLOCK_REALTIME, &stop);
    double timed=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/(double)BILLION;
    printf("SCHED_OTHER");
    printf("\n%lf\n",timed);
    histo(timed);
}
void* countB(void *diff)
{
    struct sched_param prio;
    int* d=(int*)diff;
    prio.sched_priority=*d;
    pthread_setschedparam(ThrB,SCHED_FIFO,&prio);
    
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);

    long long int i;
    long long int k=(long long int)pow(2,32);
    for(i=0;i<k;i++);

    clock_gettime(CLOCK_REALTIME, &stop);
    double timed=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/(double)BILLION;
    printf("SCHED_FIFO");
    printf("\n%lf\n",timed);
    histo(timed);
}    
void* countC(void *diff)
{
    struct sched_param prio;
    int* d=(int*)diff;
    prio.sched_priority=*d;
    pthread_setschedparam(ThrC,SCHED_RR,&prio);
    
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);

    long long int i;
    long long int k=(long long int)pow(2,32);
    for(i=0;i<k;i++);

    clock_gettime(CLOCK_REALTIME, &stop);
    double timed=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/(double)BILLION;
    printf("SCHED_RR");
    printf("\n%lf\n",timed);
    histo(timed);
}
int main(int argc, const char** argv) 
{
    int t1,t2,t3;
    int p1=2,p2=54,p3=98;
    void* diff1=(void*)&p1;
    void* diff2=(void*)&p2;
    void* diff3=(void*)&p3;
    
    t1=pthread_create(&ThrA, NULL,&countA,diff1);
    if(t1!=0){
        printf("Error:  Thread not created\n");
    }
    t2=pthread_create(&ThrB, NULL,&countB,diff1);
    if(t2!=0){
        printf("Error:  Thread not created\n");
    }
    t3=pthread_create(&ThrC, NULL,&countC,diff1);
    if(t3!=0){
        printf("Error:  Thread not created\n");
    }
    
    t1=pthread_join(ThrA,NULL);
    t2=pthread_join(ThrB,NULL);
    t3=pthread_join(ThrC,NULL);
    t1=pthread_create(&ThrA, NULL,&countA,diff2);
    if(t1!=0){
        printf("Error:  Thread not created\n");
    }
    t2=pthread_create(&ThrB, NULL,&countB,diff2);
    if(t2!=0){
        printf("Error:  Thread not created\n");
    }
    t3=pthread_create(&ThrC, NULL,&countC,diff2);
    if(t3!=0){
        printf("Error:  Thread not created\n");
    }
    t1=pthread_join(ThrA,NULL);
    t2=pthread_join(ThrB,NULL);
    t3=pthread_join(ThrC,NULL);
   
    t1=pthread_create(&ThrA, NULL,&countA,diff3);
    if(t1!=0){
        printf("Error:  Thread not created\n");
    }
    t2=pthread_create(&ThrB, NULL,&countB,diff3);
    if(t2!=0){
        printf("Error:  Thread not created\n");
    }
    t3=pthread_create(&ThrC, NULL,&countC,diff3);
    if(t3!=0){
        printf("Error:  Thread not created\n");
    }
    t1=pthread_join(ThrA,NULL);
    t2=pthread_join(ThrB,NULL);
    t3=pthread_join(ThrC,NULL);
    return 0;
}