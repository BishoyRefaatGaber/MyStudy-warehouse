```cpp
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>

class Point {
//Costructor is private
  float x, y;
  Point(float x, float y) : x(x), y(y) {}

public:
// Provide API for initialization
  static Point NewCartesian(float x, float y) { return {x, y}; }
  static Point NewPolar(float r, float theta) {
    return {static_cast<float>(r * cos(theta)),
            static_cast<float>(r * sin(theta))};
  }
  friend std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "x : " << point.x << "   y : " << point.y;
    return os;
  }
};

int main() {

  auto p = Point::NewPolar(5, M_PI_4);
  auto u = Point::NewPolar(10, M_PI_4);

  std::cout << u << std::endl;
  std::cout << p << std::endl;
  return 0;
}

```