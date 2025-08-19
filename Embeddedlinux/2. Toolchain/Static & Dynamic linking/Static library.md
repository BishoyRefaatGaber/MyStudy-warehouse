>You can link all the libraries statically by adding -static to the command line:

$ arm-cortex_a8-linux-gnueabihf-gcc -static helloworld.c -o helloworld-static  

>If I have two source files named test1.c and test2.c, and I want to create a static library named libtest.a, then I would do the following:

**$ arm-cortex_a8-linux-gnueabihf-gcc -c test1.c
$ arm-cortex_a8-linux-gnueabihf-gcc -c test2.c
$ arm-cortex_a8-linux-gnueabihf-ar rc libtest.a test1.o test2.o
$ ls -l**

>Then I could link libtest into my helloworld program, using this:]

**$ arm-cortex_a8-linux-gnueabihf-gcc helloworld.c -ltest \
-L../libs -I../libs -o helloworld




