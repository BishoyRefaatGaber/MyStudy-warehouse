


- Installing commands

**$ git clone https://github.com/crosstool-ng/crosstool-ng.git
$ cd crosstool-ng
$ git checkout crosstool-ng-1.24.0
$ ./bootstrap
$ ./configure --prefix=${PWD}
$ make
$ make install**


- Building commands
**$ bin/ct-ng \<toolchain name>
$ bin/ct-ng menuconfigs
$ bin/ct-ng build**


• Adding the toolchain to the environmental variables 

$ PATH=~/x-tools/<The toolchan name>/bin:$PATH
