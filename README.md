# System-Calls-Stuffs-Notes

# 

https://github.com/ewdlop/IPCNote/

#

Here’s the revised text with properly formatted sources in Markdown:

---

A **system call** is a mechanism that allows user-level applications to request services from the operating system's kernel. This interface enables programs to perform operations such as process management, file handling, and device communication, which require higher privileges than those available in user mode. By providing a controlled means for applications to interact with the kernel, system calls ensure system stability and security. 

([Source: GeeksforGeeks](https://www.geeksforgeeks.org/introduction-of-system-call/))

### Types of System Calls:

1. **Process Control:**  
   Manage processes by creating, terminating, or altering their states. Examples include `fork()` and `exec()` in Unix-like systems.  
   ([Source: Javatpoint](https://www.javatpoint.com/system-calls-in-operating-system))

2. **File Management:**  
   Handle file operations such as creation, deletion, reading, and writing. For instance, `open()`, `read()`, and `write()` are common file management system calls.  
   ([Source: PhoenixNAP](https://phoenixnap.com/kb/system-call))

3. **Device Management:**  
   Facilitate communication between processes and hardware devices, including requesting device access and releasing it after use.  
   ([Source: Javatpoint](https://www.javatpoint.com/system-calls-in-operating-system))

4. **Information Maintenance:**  
   Retrieve or modify system data, such as the current time or process information. System calls like `getpid()` and `time()` serve this purpose.  
   ([Source: Javatpoint](https://www.javatpoint.com/system-calls-in-operating-system))

5. **Communication:**  
   Enable inter-process communication through mechanisms like pipes, message queues, and shared memory. Examples include `pipe()` and `shmget()`.  
   ([Source: Javatpoint](https://www.javatpoint.com/system-calls-in-operating-system))

### How System Calls Work:

When a user application needs to perform an operation that requires higher privileges, it invokes a system call. This process typically involves:

1. **System Call Invocation:**  
   The application calls a library function corresponding to the desired system call.

2. **Mode Switch:**  
   The system transitions from user mode to kernel mode to safely execute the requested operation.

3. **Kernel Execution:**  
   The kernel performs the necessary operations, such as accessing hardware or managing resources.

4. **Return to User Mode:**  
   After completing the operation, the system switches back to user mode, and control returns to the application.  
   ([Source: PhoenixNAP](https://phoenixnap.com/kb/system-call))

This controlled interaction ensures that user applications cannot directly access critical system resources, maintaining system integrity and security.

## Why Avoiding System call?

Me: hardware dependent.

## Why avoid standard library?

Me: You are locked to vender

## Why avoid Speficic Library?

Me: People said that is premature optimization


