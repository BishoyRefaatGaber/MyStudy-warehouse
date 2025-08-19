
#### Maximum CPU utilization obtained with multitasking
#### CPU-I/O Burst Cycle
- Process execution consists of a cycle of CPU execution and I/O wait

#### Selects from among the processes in memory that are ready to run and allocates the CPU to one of them
#### CPU scheduling decisions may take place when a process:

1. Switches from running to waiting state
2. Switches from running to ready state
3. Switching from waiting to ready
4. Terminates

#### Preemptive
- Process release the CPU before it finish execution
- Example : Modern OS : Unix , Linux , Windows7
#### Non-preemptive
- Process release CPU when:
	- Running -> waiting
	- Running -> Terminated
- Example : MS windows 3.1

#### Dispatcher
- Give Control of the cpu to the process selected by the short-term scheduler:
	- switching context
	- switching to suitable mode (User or Monitor)
	- jumping to the proper location in the user program to restart that program
- Dispatch latency 
	- time taken by dispatcher to stop one process and start another running 