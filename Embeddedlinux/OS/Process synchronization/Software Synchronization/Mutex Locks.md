
> ***A problem*** 

- Hardware-bases solutions are complicated 
	- generally inaccessible to application programmers

---

> ***Mutex lock***

- Mutex lock is a Boolean variable
- Accessed only through two standard atomic operations :
	- Acquire ( )  -> must be called before entering the critical section
	- Release ( ) -> must be called right after exiting the critical section

> ***Mutual Exclusion using Mutex Locks*** 

	while (true)
	{
		== acquire lock ==
			critical section
		== release lock ==
			remainder section
	}



	class Mutex 
	{
		private bool available;
		public Mutex () { available = true; }
		public void Acquire ()  // must execute atomically
		{
			while (!available);  // busy wait
			available = false;
		}
		public void Release()  // must execute atomically
		{
			available = true;
		}
	}