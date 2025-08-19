
### Occurs when two or more threads are waiting indefinitely for an event that can be caused by only one of the waiting threads which is waiting for an event that can be caused by only the other waiting thread .

---

> ***Using a Resource***

1. Request
2. Use
3. Release

---

> ***Deadlock Conditions***

- Mutual exclusion
- Hold and wait
- No preemption
- Circular wait

---

> ***Resource Allocation Graph***

- A direct graph that can precisely describe deadlocks




> Deadlock Conditions in RAG

![[deadlock conditions in RAG.PNG]]

![[deadlock with cycle.PNG]]



> ***Methods for Handling Deadlocks***

[The idea is break one of the deadlock conditions]
- Ignore the problem pretend deadlock never occur
	- used by most OSes including linux and windows
- Use a protocol to prevent or avoid deadlocks (deadlocks never occur)
	- ***Deadlock prevention***   -> provides a set of methods  to ensure that at least one of the necessary conditions for a deadlock to occur cannot hold
	-  ***Deadlock avoidance*** -> require that the OS be given information in advance about which resources a thread will request and use during its lifetime
- Allow the system to enter a deadlock state , detect it and recover
	- An algorithm for ***deadlock detection*** and an algorithm for ***deadlock recovery***

