
- constexpr forces the const expression to be resolved in the compilation stage 
- cost used for one line expression but constexpr can used for multiline but 
	- take care that the function must be resolved in the compile time which means you can call a runn time function 

```

int getrandom()
{
return rand%10;
}

int main()
{
const int varB = getrandom();  //resolved in run time 
constexpr int varC = getrandom();  //error runtime function can't be resolved in the compile time  
}
```

- in c++11 constexpr must be one statement but the higher version it's fine 

```
constexpr int sum (int x , int y)
{
x = 1;
for (int i = 0 ; i<3;i++)
{

x+=i;
}
return x+y;

}

int main()
{
const int result = sum(10,20);  // resolved in compilation time 
cout << result;


const int result = sum (10,rand()); // resolved in run time 
cout<<result;
return 0;
}

//  if you want it to be resolved in compile time make result as constexpr
//  so it will make an error  

```

