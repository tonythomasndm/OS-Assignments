#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
struct arrayStr 
{
  char string[5][15];
  int id[5];
  int maxIndex;
};

int main() 
{
    int fd;
    char strArr[50][15];
    struct arrayStr obj;
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
    int maxIndex = 0;
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);
    while(1) 
    {
        for (int i = maxIndex ; i < maxIndex + 5; i++) 
        {
            obj.id[i - (maxIndex )] = i;
            strcpy(obj.string[i - (maxIndex )], strArr[i]);
        }
        fd = open("file", O_WRONLY);
        write(fd, &obj, sizeof(obj));
        close(fd);
        
        fd = open("file", O_RDONLY);
        read(fd, &obj, sizeof(obj));
        maxIndex=obj.maxIndex;
        close(fd);
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