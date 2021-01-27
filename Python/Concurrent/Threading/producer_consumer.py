import threading
import time

BUFFER_SIZE = 10
mutex = threading.Lock()
fillcount = threading.Semaphore(0) #items produced
emptyCount = threading.Semaphore(BUFFER_SIZE) #// remaining space

def producer():
    while (True):
        #item = produceItem();
        emptyCount.acquire()
        mutex.acquire()
        print(1)
        #putItemIntoBuffer(item);
        mutex.release()
        fillcount.release()

def consumer():
    while (True):
        fillcount.acquire()
        mutex.acquire()
        print(0)
        #item = removeItemFromBuffer();
        mutex.release()
        emptyCount.release()
        #consumeItem(item);

def main():
    t1 = threading.Thread(target = producer)
    t2 = threading.Thread(target = consumer)
    t1.start()
    t2.start()

if __name__ == "__main__":
    main()