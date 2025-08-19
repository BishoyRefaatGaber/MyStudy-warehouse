>The object code for a shared library must be position-independent, so that the runtime linker is free to locate it in memory at the next free address. To do this, add the -fPIC parameter to gcc, and then link it using the -shared option:


**$ arm-cortex_a8-linux-gnueabihf-gcc -fPIC -c test1.c
$ arm-cortex_a8-linux-gnueabihf-gcc -fPIC -c test2.c
$ arm-cortex_a8-linux-gnueabihf-gcc -shared -o libtest.so test1.o test2.o**

-----------------------------------------------

