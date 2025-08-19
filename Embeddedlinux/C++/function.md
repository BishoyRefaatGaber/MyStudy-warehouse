

> pass by pointer vs pass by pointer 


- pass  by pointer
```
void PTR (int * ptr*)
{
*ptr = 100;
}
int num = 300; 
PTR(&num);
```

- pass by reference
```
void REF(int &ref)
{
ref = 100;
}
int num = 300; 
REF(num);
```


- If the pointer is null so use `nullptr`
- For dynamic memory use `new`  and `delete`

--- 

> auto
- Not used in function parameters
