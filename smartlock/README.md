READ THIS BEFORE PROCEEDING

These source files are responsible for compiling into the code a Raspberry Pi actually uses to modulate the GPIO pins. That said, the binary will require superuser privileges to run, and thus should not be used in a production-environment smart lock or other related application. THE PROVISIONED SOURCE CODE IS NOT GUARANTEED TO RUN SECURELY. DO NOT USE THIS SOFTWARE WITHOUT UNDERSTANDING THE RISKS.

Instructions:
0. You absolutely need WiringPi installed to compile and link all related files into a binary.

1. Assuming you have extracted the folder, compile all files into a binary using the following:
    g++ -o [Preferred name of binary] *.cpp -lpthread -lwiringPi

2. Move the binary to /bin or /sbin depending on your needs.

Note that this program was designed to run in tandem with smartlock.py, another application developed and possibly maintained by the developer
