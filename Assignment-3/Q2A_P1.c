#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
struct arrayStr 
{
  char string[5][15];
  int id[5];
};

int main()
{
    struct arrayStr obj;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int sockfd;
    int maxIndex = 0;
    int clientSocket_fd;  
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(3000);
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
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
    bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(sockfd, 1);
    socklen_t clientSocketLength = sizeof(client_address);
    clientSocket_fd = accept(sockfd, (struct sockaddr*)&client_address, &clientSocketLength);
    struct timespec start, stop;
    clock_gettime(CLOCK_REALTIME, &start);
    while(1) 
    { 
        for (int i = maxIndex; i < maxIndex + 5; i++)   
        {
            strcpy(obj.string[i - (maxIndex)], strArr[i]);
            obj.id[i - (maxIndex)] = i;
        }
        send(clientSocket_fd, &obj, sizeof(obj), 0);
        recv(clientSocket_fd, &maxIndex, sizeof(maxIndex), 0);
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
