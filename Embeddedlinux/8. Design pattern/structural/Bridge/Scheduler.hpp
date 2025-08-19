#pragma once
#include "OperatingSystem.hpp"
#include <iostream>
#include <memory>
class ThreadScheduler {
protected:
  std::shared_ptr<ThreadScheduler_Implementation> ThrdSkdlrImplmnt;

public:
  //   ThreadScheduler(
  //       std::shared_ptr<ThreadScheduler_Implementation> ThrdSkdlrImplmnt)
  //       : ThrdSkdlrImplmnt(ThrdSkdlrImplmnt) {}
  virtual ThreadScheduler_Implementation &PerformScheduler() = 0;
};

class PreemptiveThreadScheduler : public ThreadScheduler {
public:
  PreemptiveThreadScheduler(
      std::shared_ptr<ThreadScheduler_Implementation> ThrdSkdlrImplmnt) {
    this->ThrdSkdlrImplmnt = ThrdSkdlrImplmnt;
  }
  ThreadScheduler_Implementation &PerformScheduler() override {
    std::cout << "Performing Preemptive Thread Scheduler" << std::endl;
    return *ThrdSkdlrImplmnt;
  }
};

class TimeSlicedThreadScheduler : public ThreadScheduler {
public:
  TimeSlicedThreadScheduler(
      std::shared_ptr<ThreadScheduler_Implementation> ThrdSkdlrImplmnt) {
    this->ThrdSkdlrImplmnt = ThrdSkdlrImplmnt;
  }
  ThreadScheduler_Implementation &PerformScheduler() override {
    std::cout << "Perform Time Sliced Thread Scheduler" << std::endl;
    return *ThrdSkdlrImplmnt;
  }
};
