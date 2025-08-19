
> static

`static_cast<type>(variable)`
***compile time cast***

> dynamic




> c-style

`(type)variable



> const

`const_cast<type>(variable)
***used to remove the constness of a variable***


> reinterpret

`reinterpret_cast<pointer type>(ptr)`

pointer type -> ex: char*
***used to deal with pointers 

- very dangerous cause it may extend the memory reserved for a variable and may overwrite another data

```
class A
{
puplic : 
int x=10;
void fun_a()
{
std::cout<<"In class A\n";
}
}

class B
{
public :
int x = 12;
void fun_b()
{
std::cout<<"B\n";
}
}

int main ()
{
B* x = new B();
A* new_a = reinterpret_cast<A*>(x);
new_a->fun_a(); //inclass A
std::cout<<new_a->x<<std::endl;  //from class B
return 0;
}


```



---

In practise

- Avoid C-style casts. Be sure about what you want while casting.
- Use static_cast wherever you were using C-style cast.
- Use dynamic_cast with polymorphic classes.
- Use const_cast when you need to remove const or volatile qualiﬁers.
* Use reinterpret_cast when you have no options.

[Note]:  const_cast and reinterpret_cast should generally be avoided because they can be harmful if used incorrectly.


Don’t use it unless you have a very good reason to use them.