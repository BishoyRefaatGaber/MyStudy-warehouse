
- is a technique of a compiler to illuminate the temporary objects 

```
// the class in the move semantics note named as RuleOf5


Integer Add (int a , int b)
{
Integer temp (a+b);
return temp;
}

int main(){
Integer a= 3;  // Integer a = Integer(3)
               // The compiler will omit the copy constructor and will call the parameterized one 
				// if you turn off the elidation in the g++ the move constructor will be called instead of the copy constructor
				

return 0 ;
}
```


---

> std move function

- always used with lvalue
- Forces the compiler to  use the move semantics instead of the copy semantics
- used if you want to release the resources in the middle of code 
- you can pass that object through a function using the move 

```
int main()
{
Integer a(1);
auto b{std::move(a)};
return 0;
}
```