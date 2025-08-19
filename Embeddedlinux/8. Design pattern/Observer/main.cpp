#include "Observer.hpp"
#include "Subject.hpp"
#include <memory>
int main() {

  Robbery rob;
  std::shared_ptr<Observer1> Theif1 = std::make_shared<Theif>();
  std::shared_ptr<Observer1> Theif2 = std::make_shared<Theif>();
  std::shared_ptr<Observer1> Theif3 = std::make_shared<Theif>();

  rob.Attach(Theif1);
  rob.Attach(Theif2);
  rob.Attach(Theif3);

  rob.DoJob("all clear");
  rob.DoJob("all clear");
  rob.DoJob("Harry up there is a police offecer comming");
  rob.DoJob("Harry up there is a police offecer comming");
  rob.DoJob("all clear");
  rob.DoJob("all clear");

  return 0;
}