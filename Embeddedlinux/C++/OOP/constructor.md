

### Types of constructor 
#### copy constructor 
- It will cause problems if we are using a row pointer to allocate memory 
- It will be fine if we are using normal variables

> Rule of 3
- All should be define if a user implements any of them 
	- Destructor
	- Copy constructor
	- copy assignment operator
- This will be due to allocation of some resource in a constructor
	-  Destructor -> free resources
	- Copy constructor -> perform deep copy
	- copy assignment operator -> perform a deep copy

#### Delegation constructor

```
class Class {

Class():Class(val1,val2){}
Class(arg1,arg2){
// code
}
}

```


---

> delete 

- used to prevent using a function in the class
```
void nee (float) = delete;
```

---

> R-value reference

- reference to an rvalue -> &&
