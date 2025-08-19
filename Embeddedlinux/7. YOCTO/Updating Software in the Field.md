

- From where do updates originate ??
	- Local updates -> over an SD card or USB flash
	- Remote updates -> over a remote server
	- OTA -> Remotely

---------------------------------------------------------

- What to update ?
	- Bootloader
	- Kernel
	- Root filesystem
	- System application
	- Device-specific data

------------------------------------------------------------------------

- ease of update  ---> Bootloader ---> Kernel ---> Root file system ---> System application
- Frequently  ---> Bootloader ---> Kernel ---> Root file system ---> System application

---------------------------------------------------------------------

- Bootloader : 
	 The most risky process especially with out backup 
- Kernel : 
	- Binary image -> stored in the root filesystem
	- Device tree binary -> stored alongside the kernek binary
	- Kernel modules 
- Root filesystem
	 - 