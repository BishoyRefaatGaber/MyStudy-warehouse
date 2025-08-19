```cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
struct Shape {
  virtual std::string str() const = 0;
};

struct Circle : Shape {

  float radius;
  Circle() {}
  Circle(float radius) : radius(radius) {}
  std::string str() const override {
    std::ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
  void resize(float factor) { radius *= factor; }
};

struct Square : Shape {

  float side;
  Square() {}
  Square(float side) : side(side) {}
  std::string str() const override {
    std::ostringstream oss;
    oss << "A square of side " << side;
    return oss.str();
  }
};

struct ColoredShape : Shape  // New attribute without touching the old ones
{
  Shape &shape;
  std::string color;
  ColoredShape(Shape &shape, const std::string &color)
      : shape(shape), color(color) {}
  std::string str() const override {
    std::ostringstream oss;
    oss << shape.str() << " has the color  " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape // New attribute without touching the old ones
{
  Shape &shape;
  uint8_t transparency;
  TransparentShape(Shape &shape, uint8_t transparency)
      : shape(shape), transparency(transparency) {}
  std::string str() const override {
    std::ostringstream oss;
    oss << shape.str() << " has "
        << static_cast<float>(transparency) / 255.f * 100.f
        << "% tranceparency";
    return oss.str();
  }
};

int main() {
  Square square{5};
  ColoredShape red_square{square, "red"};
  std::cout << square.str() << std::endl << red_square.str() << std::endl;

  TransparentShape my_square(red_square, 51);
  std::cout << my_square.str() << std::endl;

  Circle circle(5);
  circle.resize(3); // can use all it's properities

  ColoredShape red_circle(circle, "red");
  //red_circle.resize(3); // Can't access resize any more! :(   
  return 0;
}

```