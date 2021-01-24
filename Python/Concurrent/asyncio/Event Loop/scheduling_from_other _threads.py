import asyncio
import threading

def another_thread(loop):
    timeout = 1
    # Create a coroutine
    coro = asyncio.sleep(1, result=3)

    # Submit the coroutine to a given loop
    future = asyncio.run_coroutine_threadsafe(coro, loop)

    # Wait for the result with an optional timeout argument
    try:
        result = future.result(timeout)
        print(result)
    except asyncio.TimeoutError:
        print('The coroutine took too long, cancelling the task...')
        future.cancel()
    except Exception as exc:
        print(f'The coroutine raised an exception: {exc!r}')
    else:
        print(f'The coroutine returned: {result!r}')



loop = asyncio.get_event_loop()
t1 = threading.Thread(target=another_thread,args=(loop,), name = "thread1")
t1.start()
t1.join()
