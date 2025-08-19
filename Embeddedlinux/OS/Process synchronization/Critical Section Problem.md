
- critical section is a segment of code , in which the process may be accessing and updating data that is **shared** with other processes .
- When one process is executing in its critical section , no other process should be allowed to execute in its critical section
- An ***==entry section==*** is a segment of code , in which the process requests permission to enter its critical section 
- An ***==exit section==*** is a segment of code that follows the critical section

---

> ***Cooperating Process Implementation**

	while (true)
	{
		== entry section ==
			critical section
		== exit section ==
			remainder section
	}

---

> ***Solution Requirements**

- Mutual exclusion
- Progress
- Bounded waiting
