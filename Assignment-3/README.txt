For this question 2, 
We need to perform interprocess communication between two processes
These two processes do the following tasks:
P1: This process generates an array of random 50 strings of length 10 and sends five consecutive strings to Process P2 along with their ids
P2: This process returns the highest id among these accepted strings and prints the id and the string on the console

On recieving the acknowledgement packet from process2, Process 1 sends another next 5 Strings with the string elements starting from the acknoledged id

It is implemented in three different techniques:
1) Unix domain Sockets - referenced from ibm - socket_addrs data structure - using client and server as named
 data structure 
2) FIFOs - referenced from lkd - mkfifo - write only-read only- used by both the processes at the same time
3) Shared Memory -referenced from ibm -memory shared between two processes

time.h functions were used to calculate the times