
/dts-v1/;
{
[label--->]	[intc]: interrupt-controller@48200000 {
		compatible = "ti,am33xx-intc";
		interrupt-controller;
		\#interrupt-cells = <1>;[<--- how many cells needed to represent the interrupt source **(interrupt request (IRQ))**]
		reg = <0x48200000 0x1000>;
	};
	lcdc: lcdc@4830e000 {
		compatible = "ti,am33xx-tilcdc";
		reg = <0x4830e000 0x1000>;
		interrupt-parent = <&intc>;[<--- reference to the interrupt controller  ]
		interrupts = <36>;
		ti,hwmods = "lcdc";
		status = "disabled";
	};
};


> nterrupt-cells

->->-> Other interrupt controllers may use additional cells to characterize the interrupt; for example, to indicate whether it is edge or level triggered. The number of interrupt cells and their meanings is described in the bindings for each interrupt controller.

