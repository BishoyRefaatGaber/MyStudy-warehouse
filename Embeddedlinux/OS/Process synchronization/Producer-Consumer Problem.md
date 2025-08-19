
 > ***Data Inconsistency***

- Processes can execute concurrently
- The CPU scheduler switches rapidly between processes
- A cooperating processes can share data with other processes 
- [Concurrent access to shared data may result in data inconsistency]

 ---


> ***Producer-Consumer Problem***

- Known as ***Bound-buffer problem*** 
- Two processes , the producer and the consumer are both ***sharing a common , fixed-size buffer used as a queue*** 
- The [producer] ***generates data and puts it into the buffer*** , the [consumer] ***removes the data from the buffer*** 
- The problem is :
	- The producer won't try to add data into the buffer if it's full 
	- The consumer won't try to remove data from an empty buffer

---

> ***Proposed Solution - Shared Data**

	class Item {.....}
	int in = 0;
	int out = 0;
	int count = 0;
	const int bufferSize = 10;
	Item [] buffer = new Item[bufferSize];

---
> ***Proposed Solution - Producer**

	Item nestProduced
	while (true)
	{
		// produce an item in nextProduced
		while (count == bufferSize);  // do nothing
		buffer[in] = nextProduced;
		in = (in + 1) % bufferSize;
		count++;
	}

---
> ***Produced Solution - Consumer**

	Item nextCondumed;
	while (true)
	{
		while (count == 0); // do nothing
		nextConsumed = buffer[out];
		out = (out + 1) % bufferSize;
		count--;
		//consume the item in nextConsumed
	}

---

> Race Condition 

![[Race Condition.PNG]]

---

