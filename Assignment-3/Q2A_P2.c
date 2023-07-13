#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
struct arrayStr 
{
  char string[5][15];
  int id[5];
};

int main() 
{
  struct sockaddr_in server_address, client_address;
  int socket_fd;
  int maxIndex;
  struct arrayStr obj;
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
  
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(3000);

  connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address));
  int i=0;
  while(i < 10)
  {
    recv(socket_fd, &obj, sizeof(obj), 0); 
    for (int j=0;j<5;j++)
    printf("String id : %d\tString : %s\n\n", obj.id[j],obj.string[j]);
    maxIndex = obj.id[4];
    send(socket_fd, &maxIndex, sizeof(maxIndex), 0);
    i++;
  }
  return 0;
}