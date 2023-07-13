Here 
For Question 1.1
We have implemented the following SysCalls
1) sched_param structure is created for setting the schedule priority values
2) pthread_setschedparam()- accepts thread id, scheduling policy and struct sched_param with the priority that we want to implement
3) clock_gettime()- accepts the CLOCK_REALTIME and stores that value in struct timespec start and similarly after the process ends, it stores the stop value in struct timespec stop
4) pthread_create()- accepts thread id, accepts thread attributes, function pointer and function arguments and creates a thread
5) pthread_join()- accepts thread id, and combines the thread with its parent

Displaying Histograms:
1) Used fopen in write mode to save the inputs into text file, then used python to display the histograms
2) Displayed according to policies on the basis of time and priorities and the x-axis has the time

What does it do ?
It creates three threads and runs them parallely and each thread performs the function of counting from 0 to 2 to the power of 32.

For Question 1.2
We have implemented the following SysCalls
1) fork()- Used for forking the process and creating child process
2) execv() - Used for executing
3) struct sched_param - used for changing the priority of the process
4) sched_setscheduler() - used for setting the process schedule policy and priority
5) clock_gettime()- accepts the CLOCK_REALTIME and stores that value in struct timespec start and similarly after the process ends, it stores the stop value in struct timespec stop
6) waitpid()- helps in terminating the child process

Displaying Histograms:
1) Used fopen in write mode to save the inputs into text file, then used python to display the histograms
2) Displayed according to policies on the basis of time and priorities and the x-axis has the time

What does it do ?
It creates three processes and runs them parallely and each process performs the function of compiling the kernel.