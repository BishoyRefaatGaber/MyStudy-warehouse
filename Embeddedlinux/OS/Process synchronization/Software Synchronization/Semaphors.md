
> ***Semaphore***

- A semaphore is an integer variable 
- Accessed only through two standard atomic operations :
	- Wait ( ) -> must be called before entering the critical section
	- Signal ( ) -> must be called right after exiting the critical section

---

> ***Semaphore Implementation***

	class Semaphore
	{
		private int value ;
		public semaphore (int initial) { value = initial;}
		public void wait()
		{
			while (value <= 0); // busy wait
			value--;
		}
		public void Signal ()
		{
			value++;
		}
	}

---

> ***Counting versus Binary Semaphores***

- Binary semaphore
	- behave similarly to mutex locks
	- value can range only between 0 and 1
	- can be used to provide mutual exclusion

- Counting semaphore
	- value can range over an unrestricted domain
	+ can control access to a resource consisting of a finite number of instances
	+ the semaphore is initialized to the number of available resources instances 

---

> ***Execute S2 only after S1 using Semaphores***

Semaphore synch = new Semaphore (0);


	public void process1()           |         public void process2()
	{                                |         {
		S1;                            |            synch.Wait();
		synch.Signal();                |            S2;
	}                                |        }

---

## The Busy-Wait Problem

- when a process execute ***Wait ( )***  it enters a ***==busy wait loop==***
- instead of keeping the cpu busy , a process can suspend itself
- the cpu scheduler then can select another process to execute 
- a suspend process should be restarted when Signal1 ( )  is called 


> ***Semaphore Implementation***

	class Semaphore
	{
		private int value;
		public Semaphore (int initial) { value = initial;}
		public void Wait()
		{
			while (value <= 0);  // busy wait <that is the problem>
			value--;
		}
		public void Signal()
		{
			value++;
		}
	}


> ***Semaphore implementation (No-Busy-Wait)***

	private int value;
	private Queue<Process> process;
	public Semaphore(int initailValue)
	{
		value = initialValue;
		processes = new Queue<process>();
	}
	public void Wait()
	{
		value--;
		if(value < 0)
		{
			Process p = // calling process
			processes.Enqueue(p);
			p.Sleep(); //gone to the wait queue
		}
	}
	void Signal()
	{
		value++;
		if(value <= 0)
		{
			if(processes.Count > 0)
			{
				Process p = processes.Dequeue();
				Wakeup(p);
			}
		}
	}
