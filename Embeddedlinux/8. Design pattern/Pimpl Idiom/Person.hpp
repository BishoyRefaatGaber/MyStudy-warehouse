#pragma once

#include <string>

class Person {
public:
  std::string name;
  class PersonImpl; // used to hide some data or functions
  PersonImpl *impl;
  Person();
  ~Person();
  void greet();
};