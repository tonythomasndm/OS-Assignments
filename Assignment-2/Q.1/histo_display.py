import matplotlib.pyplot as plt
file = open('file.txt', 'r')
s=file.readline()
lis1=[]
lis2=[]
lis3=[]
c=0

for i in s.split():
    c+=1
    
    if(c==1 or c==4 or c==7):
        lis1.append(float(i))
    if(c==2 or c==5 or c==8):
        lis2.append(float(i))
    if(c==3 or c==6 or c==9):
        lis3.append(float(i))    

plt.hist(lis1, bins=10)
plt.title("SCHED_OTHER")
plt.xlabel("Time")
plt.show()

plt.hist(lis2, bins=10)
plt.title("SCHED_FIFO")
plt.xlabel("Time")
plt.show()


plt.hist(lis3, bins=10)
plt.title("SCHED_RR")
plt.xlabel("Time")
plt.show()