#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sched.h>
#define BILLION 1000000000L
pid_t pid1, pid2,pid3, wpid1,wpid2,wpid3;
double timed;
void histo(double x)
{
    FILE *ptr;
    ptr = fopen("file.txt","a");
    fprintf(ptr,"%lf ",x);
    fclose(ptr);
}
void kernel_compileA(int p)
{
    struct sched_param prio;
    prio.sched_priority=p;
    sched_setscheduler(pid1,SCHED_OTHER,&prio);
    // struct timespec start, stop;
    // clock_gettime(CLOCK_REALTIME, &start);
    if(execv("./kernel_compile_steps.sh",NULL)<0){
            printf("Error in execv()\n");
    }
    // clock_gettime(CLOCK_REALTIME, &stop);
    // timed=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/(double)BILLION;
    // histo(timed);

}
void kernel_compileB(int p)
{
    struct sched_param prio;
    prio.sched_priority=p;
    sched_setscheduler(pid2,SCHED_FIFO,&prio);
    // struct timespec start, stop;
    // clock_gettime(CLOCK_REALTIME, &start);
    if(execv("./kernel_compile_steps.sh",NULL)<0){
            printf("Error in execv()\n");
    }
    // clock_gettime(CLOCK_REALTIME, &stop);
    // timed=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/(double)BILLION;
    // histo(timed);

}
void kernel_compileC(int p)
{
    struct sched_param prio;
    prio.sched_priority=p;
    sched_setscheduler(pid3,SCHED_RR,&prio);
    // struct timespec start, stop;
    // clock_gettime(CLOCK_REALTIME, &start);
    if(execv("./kernel_compile_steps.sh",NULL)<0){
            printf("Error in execv()\n");
    }
    // clock_gettime(CLOCK_REALTIME, &stop);
    // timed=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/(double)BILLION;
    // histo(timed);

}

int	main(int argc, char *argv[])
{   int pt;
    if(argv[1]!=NULL){
        pt=strtol(argv[1],NULL,10);
    }else{
        pt=0;
    }
    struct timespec start1, start2, start3, stop1, stop2, stop3;
    clock_gettime(CLOCK_REALTIME, &start1);   
    pid1=fork();
    clock_gettime(CLOCK_REALTIME, &start2);
    pid2=fork();
    clock_gettime(CLOCK_REALTIME, &start3);
    pid3=fork();
    if(pid1<0){
        printf("Error in fork() : Could not create a child process\n");
    }
    else if(pid1==0 && pid2>0 &&pid3>0){
        kernel_compileA(pt);
    }
    else if(pid1>0 && pid2==0 && pid3>0){
        kernel_compileB(pt);
    }
    else if(pid1>0 && pid2>0 && pid3==0){
        kernel_compileC(pt);
    }
    if(pid1>0 && pid2>0 && pid3>0)
    {
        wpid1=waitpid(pid1,NULL,WUNTRACED);
        if(wpid1<0)
        {
            printf("Error in waitpid(): Process not terminated");
        }
        if(wpid1>=0)
        {printf("SCHED_OTHER");
        clock_gettime(CLOCK_REALTIME, &stop1);
        timed=(stop1.tv_sec-start1.tv_sec)+(double)(stop1.tv_nsec-start1.tv_nsec)/(double)BILLION;
        printf("\n%lf\n",timed);

        histo(timed);}
     }
    if(pid1>0 && pid2>0 && pid3>0)
    {
        wpid2=waitpid(pid2,NULL,WUNTRACED);
        if(wpid2<0)
        {
            printf("Error in waitpid(): Process not terminated");
        }
        if(wpid2>=0)
        {printf("SCHED_FIFO");
        clock_gettime(CLOCK_REALTIME, &stop2);
        timed=(stop2.tv_sec-start2.tv_sec)+(double)(stop2.tv_nsec-start2.tv_nsec)/(double)BILLION;
        printf("\n%lf\n",timed);
        histo(timed);}
    }
    if(pid1>0 && pid2>0 && pid3>0)
    {
        wpid3=waitpid(pid3,NULL,WUNTRACED);
        if(wpid3<0)
        {
            printf("Error in waitpid(): Process not terminated");
        }
        if(wpid3>=0)
        {printf("SCHED_RR");
        clock_gettime(CLOCK_REALTIME, &stop3);
        timed=(stop3.tv_sec-start3.tv_sec)+(double)(stop3.tv_nsec-start3.tv_nsec)/(double)BILLION;
        printf("\n%lf\n",timed);
        histo(timed);}
     }

    return 0;
}
