- The programming interface to the Unix operating system is defined in the C language,
which is now defined by the POSIX standards.

- The C library is the implementation of
that interface; it is the gateway to the kernel for Linux programs.

Application -> C library -> Linux Kernel 

There are Four options of the C library
- glibc
- musl libc
- uClibc-ng
- eglibc

- A common way of choosing the C library

	**if (using uClinux)
	{
		uClibc-ng
	}
	else if ( <32 MB storage )
	{
		musl libc  or  uClibc-ng
	}
	else 
	{
		glibc
	}**