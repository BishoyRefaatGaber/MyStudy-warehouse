- happen when i need tor create a temporary object and return it from a function


> Rule of 5

-  If a class has ownership semantics,then you must provide a user-defined 
	- Destructor
	- copy constructor
	- copy assignment operator
	- move constructor
	- move assignment operator
- This is to ensure proper handling of the underlying resource

```
  

class RuleOf5 {
int Val;
int *ptr;
public:

// Default constructor
RuleOf5();

// Parameterized constructor
RuleOf5(int value);

// Copy constructor -> take an object as a constant
RuleOf5(const RuleOf5 &obj);

// Move constructor
RuleOf5(RuleOf5 &&obj);

// Copy assignment
RuleOf5 &operator=(const RuleOf5 &obj);

// Move assignment
RuleOf5 &operator=(RuleOf5 &&obj);

int GetValue()
const; // Don't forget that if the function doesn't modify any member of
// the class make it as const for performance reasons

void SetValue(int value);
~RuleOf5();
};



  

RuleOf5::RuleOf5() { ptr = new int(0); }
RuleOf5::RuleOf5(int value) { ptr = new int(value); }
RuleOf5::RuleOf5(const RuleOf5 &obj) { ptr = new int(*obj.ptr); }
RuleOf5::RuleOf5(RuleOf5 &&obj) {
ptr = obj.ptr;
obj.ptr = nullptr;
}

RuleOf5 &RuleOf5::operator=(const RuleOf5 &obj) {
if (this == &obj) {
return *this;
}

delete ptr;
ptr = new int(*obj.ptr);
return *this;
}

RuleOf5 &RuleOf5::operator=(RuleOf5 &&obj) {
if (this == &obj) {
return *this;
}

delete ptr;
ptr = obj.ptr;
obj.ptr = nullptr;
return *this;
}

int RuleOf5::GetValue() const { return *ptr; }
void RuleOf5::SetValue(int value) { *ptr = value; }
RuleOf5::~RuleOf5() { delete ptr; }


```




---

> Rule of 0

- If the class doesn't have ownership semantics then don't provide any user defined function from the rule of 5 
- Leave the compiler automatically synthesize the necessary function
- If you implemented any of the 5 then the compiler will not be able to create the others
- 