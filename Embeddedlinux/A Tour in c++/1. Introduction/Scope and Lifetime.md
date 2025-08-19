
- A declaration introduces its name into a scope:
	- Local scope -> local name
	- Class scope -> member name / class member name 
	- Namespace scope -> namespace member name
	- Global namespace -> global name 
-  An object will be destroyed at the end of its scope :
	- namespace -> the end of the program
	- member -> the point of destruction of the object of which it is a member
	- Objected created by `new` -> destroyed by `delete`
