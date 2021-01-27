import asyncio

async def main():
    sem = asyncio.Semaphore(10)
    # ... later
    await sem.acquire()
    try:
        # work with shared resource
        print(1)
    finally:
        sem.release()