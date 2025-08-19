```cpp
#include <iostream>
#include <sstream>
#include <vector>

class HtmlBuilder;
class HtmlElement {
  friend class HtmlBuilder;
  HtmlElement() {}
  HtmlElement(const std::string &name, const std::string &text)
      : name(name), text(text) {}

public:
  std::string name, text;
  std::vector<HtmlElement> elements; //----------------------------
  const size_t indent_size = 2;

  std::string str(int indent = 0) const {
    std::ostringstream oss;

    std::string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << std::endl;
    if (text.size() > 0)
      oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;
    for (const auto &e : elements)
      oss << e.str(indent + 1);
    oss << i << "</" << name << ">" << std::endl;
    return oss.str();
  }
  static HtmlBuilder
  create(std::string rname); //-----> added to provide some type of enforcement
                             // for a user to use HtmlBuilder
};

class HtmlBuilder {
  HtmlElement root;

public:
  HtmlBuilder() {}
  HtmlBuilder(std::string root_name) { root.name = root_name; }
  HtmlBuilder &
  add_child(std::string child_name,
            std::string child_text) //---> type from void to HtmlBuilder
  {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }
  std::string str() const { return root.str(); }

  HtmlElement build() { return root; }
  operator HtmlElement() const // Confert from HtmlBuilder to HtmlElement
  {
    return root;
  }
};

HtmlBuilder HtmlElement::create(std::string rname) {
  return {rname};
} //-------------->

int main() {

  HtmlBuilder builder{"ul"};
  builder.add_child("li", "hello")
      .add_child("li", "world")
      .add_child("test0", "test1"); // Fluent interface

  std::cout << builder.str() << std::endl;

  auto Builder0 = HtmlElement::create("ul").add_child(
      "std::string child_name",
      "std::string child_text"); // Enforcement for the user

  HtmlElement Builder1 = HtmlElement::create("ul").add_child(
      "std::string child_name",
      "std::string child_text"); // Confert from HtmlBuilder to HtmlElement

  auto e = HtmlElement::create("std::string rname")
               .add_child("std::string child_name", "std::string child_text")
               .build();

  std::cout << e.str() << std::endl;
  std::cout << Builder0.str() << std::endl;
  std::cout << Builder1.str() << std::endl;
  return 0;
}

```