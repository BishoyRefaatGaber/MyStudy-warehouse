#### Single responsibility principle 
- Each class in your system should have only one responsibility
- You should be able to describe what each class does without saying "and"
- Each class should have only one reason to change
- If we have that class 
	```
	public class Employee{
		public BigDecimal calculateMonthSalary(){
		........
		}
		public HoursReport productMonthltHoursReport(){
		..........
		}
		public void saveModifications(){
		...........
		}
	}
	```
Now if we add some feature in the productMonthltHoursReport(){} this change called ***intentional change*** but if we needed to change any other features due to that change we call it ***unintentional change 
- **SRP** violations leads to ***excessive coupling***
- Involving of different stakeholders in class-level function of SRP violation 
- Break features into smaller classes foe easier reuse
-> SRP Analysis Framework
- List all requirements
- Analysis each item in the list to identify potential reasons to change
- Extract functionality that change due to different reasons into standalone classes 
---
#### Open-Closed Principle
- Software entities (classes , modules , functions , ...etc) should be open for extension , but closed for modification .
- Proper utilisation of OCP allows you to provide additional business value quickly and safely
---
#### Liskov Substitution principle
***$$=======Method Rules=======$$***
- **[LSP Signature Rules]**
	- ***Contravariance of arguments***
		- If subclass implements a method from its super class , then the number of arguments should be the same 
		- The type of each argument in subclass method should be the super type of the type of the respective arguments in super class method
	- ***Covariance of results***
		- Either both superclass' and subclass' methods return, or neither does
		- If there is a result, then the type of the result in the subclass is a subtype of the type of the result in the superclass
	- ***Exception rule***
		- Exceptions thrown by a method in the subclass should be contained in the set of exceptions thrown by the respective method in the superclass
- **[LSP Method Rules]**
	- ***Pre-condition rule*** -> An assertion about the state of the system  before the method is called
		- Pre-conditions required by methods of a subclass mustn't be stronger than pre-conditions required by methods of a superclass
		 ---> A suberclass should be able to operate in all states that a superclass can operate in
	- ***Post-conditions rule*** -> An assertion about the state of the system after method execution completes
		- Post-conditions guaranteed by methods of a subclass mustn't  be weaker than Post-conditions guaranteed by methods of a superclass
		 ---> Clients shouldn't be surprised by the results of invocation of methods of a subclass
	***$$======Class Property Rules======$$***
- Invariant Rule -> An assertion about a specific class property which is always true 
	- Invariants guaranteed by a subclass must include all invariants guaranteed by a superclass
- Constraint Rule -> An assertion about how class property evolves over time
	- Constraints enforces by a subclass must include all constraints enforced by a superclass


Constraint VS Invariant 
- Invariant :
	- Independent of the history
	- Relatively easy to identify and reason about
	- The same condition is always true for all instances 
	- Can't express dynamic properties 
- Constraint :
	- Can express dynamic properties of the class
	- The condition may have a little bit changes but when it is initialised in can't be changed 

$$Design-and-document-for-inheritance-or- else-prohibit-it $$

#### Interface Segregation Principle
- Clients shouldn't be forced to depend on methods they don't use
- Benefits :
	- Explicit and clear dependencies
	- More readable code without puzzling empty methods
	- Easy to find all clients which are interested in a specific message
	- Safe and easy addition of new message types in the future
- ISP is a principle of least knowledge and information hiding

#### Dependency Inversion Principle
- High-level modules should not depend on low-level modules; Both should depend on abstractions &
- Abstractions should not depend on details; Details should depend on abstractions
- DIP advocates for strategic use of abstractions
- Benefits :
	- Protection from future changes in requirements
	-  Reusability
	- Break dependency on external modules
	- Easier integration between modules
	- Better visibility and accountability
	- 