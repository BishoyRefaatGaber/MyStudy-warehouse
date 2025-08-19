>To compile BusyBox, you would type this:

**$ make CROSS_COMPILE=arm-cortex_a8-linux-gnueabihf-**

>you can set it as a shell variable:

**$ export CROSS_COMPILE=arm-cortex_a8-linux gnueabihf-
$ make**

[->->->]In the case of U-Boot and Linux, you also have to set the make variable ARCH to one of the machine architectures they support