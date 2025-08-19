
- Main memory 
	- Low memory  -> operating system + interrupt vector table
	- High memory -> User processes


- Single-partition allocation
	- ***Relocation-register***
		- Containing the value of the smallest physical address
		- Used to protect user processes from :
			- Each other  
			- From changing operating system code and data
	- ***Limit-register***
		- Containing range of logical addresses for the running process


![[Relocation and limit REGs.PNG]]


- Multi-partition allocation 
	- Operating system maintains information about :
		a) Allocated partitions             b) Free partitions (hole)

![[Multi allocation.PNG]]

