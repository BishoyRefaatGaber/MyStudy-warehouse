It is composed of four main parts that together implement the POSIX API :
- libc ---> The main C library that contains the well-known POSIX functions such as printf, open, close, read, write, and so on
- libm ---> Contains math functions such as cos, exp, and log
- libpthread ---> Contains all the POSIX thread functions with names beginning with pthread_
- librt ---> Has the real-time extensions to POSIX, including shared memory and asynchronous I/O

->->-> The \<libc>  is always linked in but the others have to be explicitly linked with the -l option

->->-> The parameter to < -l> is the library name with lib stripped off . 
EX : libm -> -lm 
$ arm-cortex_a8-linux-gnueabihf-gcc myprog.c -o myprog -lm


