#pragma once
#include <iostream>
#include <string>
class Observer1 {

public:
  virtual void update(std::string mesg) = 0;
};

class Theif : public Observer1 {

public:
  void update(std::string mesg) override { std::cout << mesg << std::endl; }
};

class Observer2 {

public:
  virtual void update(std::string mesg) = 0;
};