
>When the bootloader passes control to the kernel, it has to pass some basic information, which includes the following:

• The machine number, which is used on PowerPC and Arm platforms without support for a device tree, to identify the type of the SoC.
• Basic details of the hardware that's been detected so far, including (at the very least) the size and location of the physical RAM and the CPU's clock speed.
• The kernel command line.
• Optionally, the location and size of a device tree binary.
• Optionally, the location and size of an initial RAM disk, called the initial RAM file system (initramfs).

