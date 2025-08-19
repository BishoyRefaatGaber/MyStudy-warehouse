
- Sysroot
	- is a directory that contain sub directories for libraries , header file and other configuration files .
	  - The location as example 
             /home/birg16/x-tools/aarch64-rpi4-linux-gnu/aarch64-rpi4-linux-gnu/sysroot
	- Contain : 
		- lib ---> contain the shared objects for the C library and the dynamic linker/loader ld-linux
		- usr/lib ---> The static library archive files for the C library, and any other libraries that may be installed subsequently
		- usr/include ---> Contains the headers for all the libraries
		- usr/bin ---> Contains the utility programs that run on the target, such as the ldd command
		- usr/share ---> Used for localization and internationalization
		- sbin ---> Provides the ldconfig utility, used to optimize library loading paths