#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>


struct arrayStr 
{
  char string[5][15];
  int id[5];
  int maxIndex;
};

int main() 
{
    struct arrayStr obj;
    int fd,maxIndex;
    mkfifo("file", 0666);
    int i=0;
    while(i < 10) 
    {    
        fd = open("file", O_RDONLY);
        read(fd, &obj, sizeof(obj));
        close(fd);
        for (int j=0;j<5;j++)
        printf("String id : %d\tString : %s\n\n", obj.id[j],obj.string[j]);
        maxIndex = obj.id[4];
        obj.maxIndex=maxIndex;
        
        fd = open("file", O_WRONLY);
        write(fd, &obj, sizeof(obj));
        close(fd);
        i++;
    }
    return 0;
}