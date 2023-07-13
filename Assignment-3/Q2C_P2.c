#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
struct arrayStr
{
   long msgType;
   char string[5][15];
   int id[5];
   int maxIndex;
};

int main() 
{
    struct arrayStr obj;
    int msgID;
    int maxIndex;
    int shmid = shmget((key_t)2345,1024, 0666 | IPC_CREAT);
    //obj.msgType = 1;
    int i=0;
    while(i<10)
    {   
         
         obj=*((struct arrayStr *) shmat(shmid,NULL,0));
         printf("%s",obj.string[0]);
        //msgrcv(msgID, &obj, sizeof(obj), 1, 0);
        for (int j=0;j<0;j++)
        printf("String id : %d\tString : %s\n\n", obj.id[j],obj.string[j]);
        maxIndex = obj.id[4];
        obj.maxIndex=maxIndex;
        shmdt((void*)&obj);
        //msgsnd(msgID, &obj, sizeof(obj), 0);
        i++;
    }
    shmctl(msgID, IPC_RMID, NULL);
    return 0;
}