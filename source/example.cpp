#include "window.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include <vector>
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

      
   Rectangle r1 {Vec2{10.0,29.0},Vec2{200, 300},Color{1,1,0}};
   Rectangle r2 {Vec2{600.0,390.0},Vec2{700, 700},Color{1,0,0}};
   Circle c1 {Vec2{300.0, 400.0}, 70.0, Color{1,0,1}};
   Circle c2 {Vec2{500.0, 600.0}, 90.0, Color{1,0,0.5}};

  std::vector<Rectangle> r;
  r.push_back(r1);
  r.push_back(r2);
  
  std::vector<Circle> c;
  c.push_back(c1);
  c.push_back(c2);

  while (!win.should_close()) {

    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);


  for (int i = 0; i < r.size(); ++i){
     if(r[i].is_inside(Vec2{float(m.first),float(m.second)}) == true){
      r[i].draw(win, Color{0,0,1});
    }
    else{
      r[i].draw(win);
    }
  }

   for (int i = 0; i < c.size(); ++i){
     if(c[i].is_inside(Vec2{float(m.first),float(m.second)}) == true){
      c[i].draw(win, Color{0,0,1});
    }
    else{
      c[i].draw(win);
    }
  }
  

    win.update();
  }

  return 0;
}

