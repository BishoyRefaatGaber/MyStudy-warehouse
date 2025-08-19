#define _USE_MATH_DEFINES

#include "DrinkFactory.hpp"

int main() {

  DrinkFactory df;
  auto c = df.make_drink("coffee", 200);
  auto b{df.make_drink("tea", 100)};
  c->prepare(400);
  return 0;
}
