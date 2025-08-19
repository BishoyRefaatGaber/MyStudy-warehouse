#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <map>

class DrinkFactory {
  std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;

public:
  DrinkFactory() {
    hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
    hot_factories["tea"] = std::make_unique<TeaFactory>();
  }
  std::unique_ptr<HotDrink> make_drink(const std::string &name, const int vol) {
    auto drink = hot_factories[name]->make(); // polymerphism
    drink->prepare(vol);
    return drink;
  }
};