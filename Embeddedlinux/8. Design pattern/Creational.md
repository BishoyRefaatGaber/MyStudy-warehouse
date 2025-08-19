## Builder
- When piecewise object construction is complicated, provide an API for doing it succinctly
##### Motivation
- Some objects are simple and can be created in a single constructor
- Other objects require a lot of ceremony to create
- Having an object with 10 constructor arguments is not productive
- Instead, opt for piecewise construction
- Builder provides an API for constructing an object step-by-step
##### Types
- Builder
- Fluent builder
- Groovy-Style Builder
- Builder Facets

---

## Factories
- A component responsible solely for the wholesale (not piecewise) creation of objects
##### Motivation
- object creation logic becomes too convoluted type
- Constructor is not descriptive
	- Name mandated by name of containing type
	- Cannot overload with same sets of arguments with different names 
	- Can turn into 'optional parameter hell'
- Object creation (non-piecewise,unlike Builder) can be outsourced to 
	- A separate function (Factory Method)
	- That may exist in a separate class (Factory)
	- Can create hierarchy of factories with Abstract Factory
#### Types
- Abstract Factory
- Inner factory
- Factory Method
- Functional factory

---

## Prototype
- A partially or fully initialised object that you copy (clone) and make use of 
##### Motivation
- Complicated objects (e.g., cars) aren't designed from scratch
	- They reiterate existing designs
- An existing (partially or fully constructed) design is a Prototype
- We make a copy (clone) the prototype and customise it
	- Requires 'deep copy' support
- We make the cloning convenient (e.g., via a Factory)
##### Types
- prototype 
- prototype factory
- prototype via serialisation


---

## Singleton

- A component which is instantiated only once
##### Motivation
- For some components it only makes sense to have one in the system 
	- Database repository
	- Object factory
- E.g., the constructor call is expensive 
	- We only do it once 
	- We provide everyone with the same instance
- Want to prevent anyone creating additional copies 
- Need to take care of lazy instantiation and thread safety
##### Types

