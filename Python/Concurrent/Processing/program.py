#                  | Multi-args   Concurrence    Blocking     Ordered-results
#---------------------------------------------------------------------
#Pool.map          | no           yes            yes          yes
#Pool.map_async    | no           yes            no           yes
#Pool.apply        | yes          no             yes          no
#Pool.apply_async  | yes          yes            no           no
#Pool.starmap      | yes          yes            yes          yes
#Pool.starmap_async| yes          yes            no           no

from multiprocessing import Process
import os

def info(title):
    print(title)
    print('module name:', __name__)
    print('parent process:', os.getppid())
    print('process id:', os.getpid())

def f(name):
    info('function f')
    print('hello', name)

if __name__ == '__main__':
    info('main line')
    p = Process(target=f, args=('bob',))
    p.start()
    p.join()
