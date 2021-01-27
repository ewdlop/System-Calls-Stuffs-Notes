import threading

readTry = threading.Semaphore(1)
resource = threading.Semaphore(1)
readMutex = threading.Semaphore(1)
writeMutex = threading.Semaphore(1)

def reader(readcount):
    readTry.acquire()
    readMutex.acquire()
    readcount +=1
    if(readcount == 1):resource.acquire()
    readMutex.release()
    readTry.release()
    #reading
    print(1)
    readMutex.acquire()
    readcount -= 1
    if(readcount == 0): resource.release()
    readMutex.release()

def writer(writecount):
    writeMutex.acquire()
    writecount += 1
    if(writecount == 0): readTry.acquire()
    writeMutex.release()
    resource.acquire()
    #writing
    print(0)
    resource.release()
    writeMutex.acquire()
    writecount -= 1
    if(writecount == 0): readTry.release()
    writeMutex.release()
 

def main():
    readcount = 0
    writecount = 1
    t1 = threading.Thread(target = reader, args=(readcount,))
    t2 = threading.Thread(target = writer, args=(writecount,))
    t1.start()
    t2.start()

if __name__ == "__main__":
    main()