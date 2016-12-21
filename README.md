# SmartlockRepo
Maintainer's note: Do NOT use this software in an industrial, civil, or military application. Use of this application's scripts and
binaries requires root access on a given machine. Furthermore, the following software lacks authentication measures necessary to keep out
unwanted visitors; what my team made is NOT suitable for production environments. We will not be held accountable for any incidents
resulting from negligence or user error as per the MIT license agreement. You have been warned.

# SmartLock Server

What is this? SmartLock Server consists of two modules responsible for manipulating a Raspberry Pi's pin states to control a servo. The
files written in C/C++ are compiled into an executable binary that performs the actual motor manipulation, whereas the Python module starts
a server that listens for Bluetooth connections from SmartLock Client instances. Upon receiving a command, SmartLock Server calls the
aforementioned binary and acknowledges the message before listening for the next message.
