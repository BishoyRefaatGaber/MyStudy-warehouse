### Adapter
- A construct which adapts an existing interface X to conform to the required interface Y
### Bridge
- A mechanism that decouples an interface (hierarchy) from an implementation (hierarchy)
##### Motivation
- Bridge prevents a ' cartezian product' complexity explosion
- Bridge pattern avoids the entity explosion
### Composite
- A mechanism for treating individual (scalar) objects and compositions of objects in a uniform manner
##### Motivation 
- Objects use other objects' fields/properties/members through inheritance and composition
- Composition lets us make compound objects
	- E.g., a mathematical expression composed of simple expressions; or
	- A group of shapes that consists of several shapes
- Composite design pattern is used to treat both single (scalar) and composite objects uniformly
	- I.e., Food and Collection <\Food> have common APIs
### Decorator
- Facilitates the addition of behaviors to individual objects 
##### Motivation
- Want to augment an object with additional functionality
- Do not want to rewrite or alter existing code (OCP)
- Want to keep new functionality separate (SRP)
- Need to be able to interact with existing structures
- Two options :
	- Aggregate the decorated object
	- Inherit from the decorator object 
##### Types : 
- Static 
- Dynamic
### Facade
- Provide a simple , easy to understand/user interface over a large and sophisticated body of code
### Flyweight
- A space optimisation technique that lets us use less memory by storing externally the data associated with similar objects
### Proxy
- A class that functions as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging pr some other added functionality.
##### Motivation
- You are calling ,for example say, foo.bar()
- This assumes that foo is in the same process as bar()
- What if, later on, you want to put all Foo-related operations into a separate process 
	- Can you avoid changing your code ??
- Proxy to the rescue!
	- Same interface , entirely different behavior
- This is called a ***communication proxy***
	- Other types : ***logging,virtual,guarding,...***
