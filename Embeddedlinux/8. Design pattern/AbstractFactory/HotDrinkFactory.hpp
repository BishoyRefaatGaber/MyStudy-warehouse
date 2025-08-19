#pragma once
#include "HotDrink.hpp"
#include <memory>

struct HotDrinkFactory {
  virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory {

  std::unique_ptr<HotDrink> make() const override {
    return std::make_unique<Tea>(); // polymerphism
  }
};

struct CoffeeFactory : HotDrinkFactory {
  std::unique_ptr<HotDrink> make() const override {

    return std::make_unique<Coffee>(); // polymerphism
  }
};
