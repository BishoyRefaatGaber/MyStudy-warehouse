
- A process can be swapped temporarily out of memory to a ==blocking store== and then brought back into memory for continued execution 

- ***Backing Store***  
	- Fast disk large enough to accommodate copies of all memory images for all users 
	- Must provide direct access to these memory images

- ***Roll out , Roll in**
	- Swapping variant used for priority-based scheduling algorithms
	- Lower-priority process is swapped out so higher-priority process can be loaded and executed
	- Modified versions of swapping are found on many systems UNIX Linux Windows


![[Swapping.PNG]]