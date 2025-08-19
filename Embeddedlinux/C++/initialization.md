
```
#include <iostream>
struct data {
int temp;
};

int main() {

// 1 - all of them can assign value
int n;      // default
int x = 10; // copy
int y(10);  // direct
int z{10};  // value
  
// 2 - {} narrow conversion
float dec = 3.5;
int value{dec};

// 3 - vexing parse
int v{};
int v(); // prototype
int v3 = 0;

// 4 - synthesize constructor
data d; // garbage
data d2{}; // seros

std::cout << d.temp << std::endl;
std::cout << d2.temp << std::endl;
return 0;
}
```


```
// constructor (int,int)
std::vector<int>v(2,3);

//initializer_list
std::vector<int>v2{2,3};
```