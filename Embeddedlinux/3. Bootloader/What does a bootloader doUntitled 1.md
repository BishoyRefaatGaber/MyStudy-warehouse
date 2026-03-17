- Initialize the system to a basic level
- Load the kernel

> When you first boot the device the only resources that are operational are a single CPU core, some on-chip static memory, and the boot ROM.

>The details of the interface between the bootloader and the kernel are architecture-specific, but in each case, it has to do two things. 

- [First, the bootloader has to pass a pointer to a structure containing information about the hardware configuration.]  
- [Second, it has to pass a pointer to the kernel command line.]


