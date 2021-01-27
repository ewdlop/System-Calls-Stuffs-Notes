import asyncio

async def main():
    lock = asyncio.Lock()

    # ... later
    await lock.acquire()
    try:
        # access shared state
        print(1)
    finally:
        lock.release()