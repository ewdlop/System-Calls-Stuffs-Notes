import asyncio

async def main():
    cond = asyncio.Condition()

    # ... later
    await cond.acquire()
    try:
        await cond.wait()
    finally:
        cond.release()