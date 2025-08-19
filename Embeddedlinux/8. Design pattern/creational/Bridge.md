```cpp
#include <iostream>

struct Renderer {
  virtual void render_circle(float x, float y, float radius) = 0;
};

struct RasterRender : Renderer {
  void render_circle(float x, float y, float radius) override {

    std::cout << "Rasterizing a circle of radius " << radius << std::endl;
  }
};

struct VectorRender : Renderer {

  void render_circle(float x, float y, float radius) override {

    std::cout << "Drawing a vector  circle of radius  " << radius << std::endl;
  }
};

struct shape {
protected:
  Renderer &renderer; // Used to hide the data inside it throw polymerphism
  shape(Renderer &renderer) : renderer(renderer) {}

public:
  virtual void draw() = 0;
  virtual void resize(float factor) = 0;
};

struct Circle : shape {
  Circle(Renderer &renderer, float x, float y, float radius)
      : shape(renderer), x{x}, y{y}, radius(radius) {}

  float x, y, radius;
  void draw() override { renderer.render_circle(x, y, radius); }

  void resize(float factor) override { radius *= factor; }
};

int main() {
  VectorRender rr;
  Circle raster_circle{rr, 5, 5, 5};
  raster_circle.draw();
  raster_circle.resize(2);
  raster_circle.draw();
  ;

  return 0;
}

```