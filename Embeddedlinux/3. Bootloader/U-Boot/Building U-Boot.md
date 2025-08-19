
**$ git clone git://git.denx.de/u-boot.git
$ cd u-boot
$ make rpi_4_defconfig     CROSS_COMPILE= *toolcahin*      ARCH=*arch*
$ make**


->->-> The results of the compilation are as follows:
• u-boot: U-Boot in ELF object format, suitable for use with a debugger
• u-boot.map: The symbol table
• u-boot.bin: U-Boot in raw binary format, suitable for running on your device
• u-boot.img: This is u-boot.bin with a U-Boot header added, suitable for uploading to a running copy of U-Boot
• u-boot.srec: U-Boot in Motorola S-record (SRECORD or SRE) format, suitable for transferring over a serial connection




---> ***If you have any trouble don't contact me*** 


