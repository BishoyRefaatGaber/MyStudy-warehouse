#pragma once
#include <iostream>
class ThreadScheduler_Implementation {

public:
  virtual void OS() {}
};

class Unix : public ThreadScheduler_Implementation {
public:
  void OS() { std::cout << "Operating System Unix" << std::endl; }
};

class JVM : public ThreadScheduler_Implementation {
public:
  void OS() { std::cout << "Operating System JVM" << std::endl; }
};

class Windows : public ThreadScheduler_Implementation {
public:
  void OS() { std::cout << "Operating System Windows" << std::endl; }
};