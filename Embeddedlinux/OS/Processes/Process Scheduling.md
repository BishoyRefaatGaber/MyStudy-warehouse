
- Maintains scheduling queues of processes : 
	- Job queue
	- Ready queue
	- Device queue
- Processes migrate among the various queues 


---

>  **Types of schedulers**

-  Short term scheduler (CPU scheduler)
	- Selects which process should be executed next and allocates CPU
	- Invoked frequently 

- Long term scheduler
	- Selects which processes should be brought into the ready queue
	- Invoked infrequently
	- Controls the degree of multiprogramming

- Medium term scheduler
	- Can be added if degree of multiple programming needs to decrease
	- Remove process from memory , store on disk bring back in from disk to continue execution : swapping