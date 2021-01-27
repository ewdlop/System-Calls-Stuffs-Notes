import threading

read = threading.Condition()
write = threading.Condition()

def reader():
    while(True):
        read.acquire()
        read.wait()
        print(1)
        read.release()
        write.notify()    
    
def writer(): 
    while (True):
        write.acquire()
        write.wait()
        print(0)
        write.release()
        read.notify()   

def main():
    t1 = threading.Thread(target = writer)
    t2 = threading.Thread(target = reader)
    t1.start()
    t2.start()

if __name__ == "__main__":
    main()