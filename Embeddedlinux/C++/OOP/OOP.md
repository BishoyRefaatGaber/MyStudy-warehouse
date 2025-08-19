
> Rule of 3
- All should be define if a user implements any of them 
	- Destructor
	- Copy constructor
	- copy assignment operator
- This will be due to allocation of some resource in a constructor
	-  Destructor -> free resources
	- Copy constructor -> perform deep copy
	- copy assignment operator -> perfor a deep copy