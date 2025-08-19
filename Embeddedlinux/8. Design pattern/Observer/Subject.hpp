#pragma once
#include "Observer.hpp"
#include <algorithm>
#include <list>
#include <memory>
#include <string>
class ISubject {

public:
  virtual void Attach(std::shared_ptr<Observer1> Obs) = 0;
  virtual void Deattach(std::shared_ptr<Observer1> Obs) = 0;
  virtual void Notify() = 0;
  virtual void DoJob(std::string alert = "all clear") = 0;
};

class Robbery : public ISubject {

private:
  std::list<std::shared_ptr<Observer1>> ListTheifs;
  std::string Mesg = "all clear";

public:
  void Attach(std::shared_ptr<Observer1> Obs) { ListTheifs.push_back(Obs); }
  void Deattach(std::shared_ptr<Observer1> Obs) { ListTheifs.remove(Obs); }
  void Notify() {
    std::for_each(ListTheifs.begin(), ListTheifs.end(),
                  [&](std::shared_ptr<Observer1> x) { x->update(Mesg); });
  }
  void DoJob(std::string alert = "all clear") {
    if (Mesg != alert) {
      Mesg = alert;
      Notify();
    }
  }
};

class SubjectB : public ISubject {

private:
  std::list<std::shared_ptr<Observer2>> ListOsers;
  std::string Mesg = "Empty";

public:
  void Attach(std::shared_ptr<Observer2> Obs) { ListOsers.push_back(Obs); }
  void Deattach(std::shared_ptr<Observer2> Obs) { ListOsers.remove(Obs); }
  void Notify() {
    std::for_each(ListOsers.begin(), ListOsers.end(),
                  [&](std::shared_ptr<Observer2> x) { x->update(Mesg); });
  }
  void DoJob(std::string alert = "Empty") {
    if (Mesg != alert) {
      Notify();
    }
    Mesg = alert;
  }
};