
- The code that runs immediately after a reset or power-on has to be stored on-chip in the SoC .
- Loaded into the chip when it is manufactured, and hence the ROM code is proprietary and cannot be replaced by an open source equivalent.
- It does not include code to initialize the memory controller, since DRAM configurations are highly device-specific, and so it can only use Static Random Access Memory (SRAM), which does not require a memory controller.
- 