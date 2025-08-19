The components :
- GNU Autoconf
- GNU Atomake
- GNU Libtool
- Gnulib

----------------------------------------------
>To configure, build and install a package for the native operating system, you would typically run the following three commands:

**| $ ./configure
| $ make
| $ sudo make install**

-----------
>You can influence the behavior of the configured script by setting these shell variables:

• [CC]: The C compiler command.
• [CFLAGS]: Additional C compiler flags.
• [CXX]: The C++ compiler command.
• [CXXFLAGS]: Additional C++ compiler flags.
• [CPP]: The C preprocessor to use.
• [LDFLAGS]: Additional linker flags; for example, if you have libraries in a non-standard directory [*lib dir*], you would add it to the library search path by adding -L [*lib dir*] .
• [LIBS]: Contains a list of additional libraries to pass to the linker; for instance, -lm for the math library.
• [CPPFLAGS]: Contains C/C++ preprocessor flags; for example, you would add -I      [*include dir*] to search for headers in a non-standard directory [*include dir*].

---
> Autotools understands three different types of machines that may be involved when compiling a package:

• [Build]: The computer that builds the package, which defaults to the current machine.
• [Host]: The computer the program will run on. For a native compile, this is left blank and it defaults to be the same computer as Build. When you are cross-compiling, set it to be the tuple of your toolchain.
• [Target]: The computer the program will generate code for. You would set this when building a cross compiler.

[->->->]  Note is that the default install directory is [*sysroot*]/usr/local/*.
You would usually install it in [*sysroot*]/usr/* so that the header files and libraries
would be picked up from their default locations.

>The complete command to configure a typical Autotools package is as follows:

**| $ CC=arm-cortex_a8-linux-gnueabihf-gcc \
./configure  --host=arm-cortex_a8-linux-gnueabihf --prefix=/usr]**

---
