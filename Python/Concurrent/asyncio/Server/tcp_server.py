import asyncio

# Asynchronous generator function to yield data from the client
async def client_data_generator(reader):
    while True:
        data = await reader.read(100)  # Read up to 100 bytes
        if not data:
            break
        yield data.decode()  # Yield the decoded data

# Handler function to manage client connections
async def handle_client(reader, writer):
    addr = writer.get_extra_info('peername')
    print(f"Connected by {addr}")

    try:
        async for message in client_data_generator(reader):
            print(f"Received {message!r} from {addr}")

            # Echo the message back to the client
            writer.write(message.encode())
            await writer.drain()  # Ensure data is sent

    except asyncio.CancelledError:
        pass
    finally:
        print(f"Closing connection from {addr}")
        writer.close()
        await writer.wait_closed()

# Main function to start the server
async def main(host, port):
    server = await asyncio.start_server(handle_client, host, port)
    addr = server.sockets[0].getsockname()
    print(f"Serving on {addr}")

    async with server:
        await server.serve_forever()

# Running the asyncio event loop
if __name__ == "__main__":
    try:
        asyncio.run(main('127.0.0.1', 8888))
    except KeyboardInterrupt:
        print("Server stopped manually")
