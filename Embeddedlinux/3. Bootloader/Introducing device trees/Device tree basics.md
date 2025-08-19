
- The Linux kernel contains a large number of device tree source files in arch/$ARCH/ boot/dts
- The device tree represents a computer system as a collection of components joined together in a hierarchy, such as a tree.

- The device tree begins with a root node, represented by a forward slash, /, which contains subsequent nodes representing the hardware of the system. Each node has a name and contains a number of properties in the form name = "value". Here is a simple example:

**/dts-v1/;
/{ [<--- root node]
	model = "TI AM335x BeagleBone";
	compatible = "ti,am33xx";
	\#address-cells = <1>;[<--- The information about the number of cells required for reg property (address)]
	\#size-cells = <1>;[<--- The information about the number of cells required for reg property (size)]
	cpus {[<--- cpu node]
		\#address-cells = <1>;
		\#size-cells = <0>;
		cpu@0 {[<-- cpu node include an @ followed by an address node   ->->->  @ is required if the node has a reg property.]
			compatible = "arm,cortex-a8"; [<---Both the root and CPU nodes have a compatible property.]
			device_type = "cpu"; [<--- describes the class of device.]
			reg = <0>;[<--- the address of the cpu it doesn't have any size]
		};
	};
	memory@0x80000000 {[<--- memory node]
		device_type = "memory";
		reg = <0x80000000 0x20000000>; /* 512 MB * [<---refers to a range of units in a register space.]
	};
};**


> **compatible Property**

->->-> The Linux kernel uses the ***compatible*** property to find a matching device driver by comparing it with the strings that are exported by each device driver in a of_device_id structure.

->->-> The value of the ***compatible*** property is composed of a ***manufacturer name*** and a ***component name***, to reduce confusion between similar devices made by different manufacturers; hence, ***ti,am33xx*** and ***arm,cortex-a8***. It is also quite common to have more than one value for the compatible property where there is more than one driver that can
handle this device.

> **device_type property**

->->-> The node name is often derived from device_type.

>reg property

->->-> A reg property consists of two values representing the real physical address and the size (length) of the range. Both are written as zero or more 32-bit integers, called cells.

->->-> If the address and size can't be represented by 32 we will use two cells for it 
**reg = <0x00000000 0x80000000 0 0x80000000>;**

->->-> CPUs have addresses as well; in a quad core device, they might be addressed as 0, 1, 2, and 3. That can be thought of as a one-dimensional array without any depth, so the size is zero. Therefore, you can see that we have **\#address-cells = <1>** and 
**\#size-cells =<0>** in the cpus node, and in the child node, cpu@0, we assign a single value to the reg property, reg = <0>.


