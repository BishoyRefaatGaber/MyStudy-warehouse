
- Many modern computer systems provide hardware ***instructions*** to : 
	- Test and modify the content of a word
	- Swap the contents of two different words
- These instructions are ***atomic*** (execute as one uninterruptible unit)

> Test and set instructions

	bool TestAndSet (bool ref value)
	{
		bool oldValue = value;
		value = true;
		return oldValue;
	}

> Mutual Exclusion using Test-and-Set

	do
	{
		while (TestAndSet(ref lock));  //do nothing
		// critical section 
		lock = false;
		// remainder section
	} while (true);

---

>  Compare-and-Swap Instruction

	int ComparendSwap(int ref value, int expected, int newValue)
	{
		int temp = value;
		if (value == expected) value = newValue;
		return temp;
	}

> Mutual Exclusion using Compare-and-Swap

	do
	{
		while (CompareAndSwap(ref lock, 0 , 1) != 0)
			;  // do nothing
		// critical section
		lock = 0;
		// remainder section
	} while (true);