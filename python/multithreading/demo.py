import threading
import time#OBS:se prefera metoda perf_counter() fata time()
            #pentru masurarea duratei executiei
def delay_function():
    temp=0
    for i in range(1000):
        for j in range(1000):
            temp=temp+1  
def mean_value():#calcul medie pentru 2 apeluri de functie
    counter=1000
    mean=0
    for i in range(counter):
        start_time=time.perf_counter()
        delay_function()
        mean=mean+time.perf_counter()-start_time
    mean=mean/counter
    print("Average time single thread:",mean)
    #medie:0.024116532600026403s
    #conform ultimei rulari a programului
count=100
timer=time.perf_counter()
for i in range(count):
    delay_function()
finish=time.perf_counter()-timer
print(count,"series:",finish)
thread_array=[]
timer=time.perf_counter()
for i in range(count):
    t=threading.Thread(target=delay_function)
    t.start()
    thread_array.append(t)
for i in range(count):
    thread_array[i].join()
finish=time.perf_counter()-timer
print(count,"threads:",finish)