import time, random
from multiprocessing import Process, Pipe, current_process
from multiprocessing.connection import wait

def foo(w):
    for i in range(10):
        w.send((i, current_process().name))
    w.close()

if __name__ == '__main__':
    readers = []

    for i in range(4):
        r, w = Pipe(duplex=False)
        readers.append(r)
        p = Process(target=foo, args=(w,))
        p.start()
        # We close the writable end of the pipe now to be sure that
        # p is the only process which owns a handle for it.  This
        # ensures that when p closes its handle for the writable end,
        # wait() will promptly report the readable end as being ready.
        w.close()

    while readers:
        for r in wait(readers):
            try:
                msg = r.recv()
            except EOFError:
                readers.remove(r)
            else:
                print(msg)

#An 'AF_INET' address is a tuple of the form (hostname, port) where hostname is a string and port is an integer.
#An 'AF_UNIX' address is a string representing a filename on the filesystem.
#An 'AF_PIPE' address is a string of the form r'\.\pipe{PipeName}'. To use Client() to connect to a named pipe on a remote computer called ServerName one should use an address of the form r'\ServerName\pipe{PipeName}' instead.