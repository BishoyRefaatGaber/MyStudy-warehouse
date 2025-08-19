
> A lot of hardware is common between SoCs of the same family and between boards using the same SoC.

>This is reflected in the device tree by splitting out common sections into include files, usually with the .dtsi extension.

>The Open Firmware standard defines ***/include/*** as the mechanism to be used,

---

- As in this snippet from vexpress-v2p-ca9.dts:
	**/include/ "vexpress-v2m.dtsi"**

->->-> Look through the .dts files in the kernel, though, and you will find an alternative include statement that is borrowed from C; for example, in am335x-boneblack.dts:

**\#include "am33xx.dtsi"
\#include "am335x-bone-common.dtsi"**

->->-> Lastly, include/dt-bindings/pinctrl/am33xx.h contains normal C macros:

**\#define PULL_DISABLE           (1 << 3)
\#define INPUT_EN                     (1 << 5)
\#define SLEWCTRL_SLOW     (1 << 6) 
\#define SLEWCTRL_FAST       0**

->->-> All of this is resolved if the device tree sources are built using the ***Kbuild*** system, which runs them through the ***C preprocessor, CPP,*** where the ***\#include*** and ***\#define***
statements are processed into text that is suitable for the device tree compiler.


