#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <time.h>
struct arrayStr
{
   long  msgType;  
   char strArr[5][15];
   int id[5];
   int maxIndex;
};

int main() 
{
    int fd;
    int maxIndex = 0;
    struct arrayStr obj;
    obj.msgType = 1;
    int shmid = shmget((key_t)2345,1024, 0666 | IPC_CREAT);
    char strArr[50][15];
    char characters[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    for(int i=0;i<50;i++)
    {
        int j=0;
        while(j<10)
        {
            strArr[i][j]= characters[rand()%(sizeof(characters)-1)];
            j++;
        }
        int k=10;
        char c='\0';
        strArr[i][k]=c;
    }
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);
    while(1)
    {
        for (int i = maxIndex ; i < maxIndex + 5; i++) 
        {
            strcpy(obj.strArr[i-(maxIndex)], strArr[i]);
            obj.id[i-(maxIndex)] = i;
        }
        void* shared_memory=shmat(shmid,NULL,0);
        shmdt(&obj);
        // msgsnd(msgID, &obj, sizeof(obj), 0);
        // msgrcv(msgID, &obj, sizeof(obj), 1, 0);
        //obj=*((arrayStr*)shmat(shmid,NULL,0));
        maxIndex=obj.maxIndex;
        maxIndex++;
        if(maxIndex==50)
        {
            break;
        }
   }
   clock_gettime(CLOCK_REALTIME, &stop);
    double timed=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/(double)1000000000;
    printf("Time taken=%lf seconds\n",timed);
   return 0;
}