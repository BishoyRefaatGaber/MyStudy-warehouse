```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define EnterFun singleton::append(__PRETTY_FUNCTION__)
#define PrintBT singleton::print()
#define ExitFun singleton::out()

class singleton {
  std::string fname;
  static std::vector<std::string> vec;
  singleton(std::string fname) : fname(fname) {} // Make the constructor private
  singleton(const singleton &) = delete; // Delete the copy constructor
  singleton operator=(const singleton &) = delete; // Delete the assignment copy operator

public:
  static void append(std::string fname) // Provide an api that deals with the data
  {
    std::cout << "Enter : " << fname << std::endl;
    vec.emplace_back(fname);
  }
  static void print() {
    std::cout << "Backtrace as follows : " << std::endl;
    std::for_each(vec.begin(), vec.end(),
                  [](std::string x) { std::cout << x << std::endl; });
  }
  static void out() {
    std::cout << "Exit : " << vec.back() << std::endl;

    vec.erase(vec.end());
  }
};
std::vector<std::string> singleton::vec{};

void fun3() {
  EnterFun;
  PrintBT;
  ExitFun;
}
void fun2() {
  EnterFun;
  fun3();
  ExitFun;
}
void fun1() {
  EnterFun;
  fun2();
  ExitFun;
}

int main() {

  EnterFun;
  fun1();
  ExitFun;
  return 0;
}
```