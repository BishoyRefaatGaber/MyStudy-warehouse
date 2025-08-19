```cpp
#include <iostream>
#include <string>
#include <vector>

struct Graphicbject {
  virtual void draw() = 0;
};

struct Circle : Graphicbject {
  void draw() override { std::cout << "Circle" << std::endl; }
};

struct square : Graphicbject {
  void draw() override { std::cout << "square" << std::endl; }
};

struct Group : Graphicbject {
  std::string name;
  std::vector<Graphicbject *> objects; // Its all about the container
  Group(const std::string &name) : name(name) {}
  void draw() override {
    std::cout << "Group " << name.c_str() << " contains : " << std::endl;
    for (auto &&o : objects) {
      o->draw();
    }
  }
};

int main() {

  Group root("root");
  Circle c1, c2;
  square S;
  root.objects.push_back(&c1);

  Group subgroup("sub");
  subgroup.objects.push_back(&c2);
  root.objects.push_back(&S);
  root.objects.push_back(&subgroup);

  root.draw();

  return 0;
}

```