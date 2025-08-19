

#### static

- member :
	- must be defined out side the class
	- if it was a const it can be defined in the class
	- can be accessed out side the class using the scope operator without an object 
	  ```
	  class data{static int m};
	  int class::m = 5;
	  void main(){std::cout<<data::m;}
	  ```

- method :
	- can be called from class or instance
	- can create a local variable in it 
	- can't access this  (normal members)
	- can access static members 


---
#### const

- member 
	- defined only in with declaration or in initializer list 
	- must be initialzed 
- method 
	- normal constant can call every thing
	- const instance can only call constant method
	- const method can't write on const attributes
	- void fun()const & void fun() are different methods 
	  const instance access const method & non-const instance access non-const method