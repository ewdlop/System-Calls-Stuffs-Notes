from multiprocessing import Manager

manager = Manager()
l = manager.list([i*i for i in range(10)])
print(l)
print(repr(l))