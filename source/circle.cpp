#include "circle.hpp"
#include <math.h>


Circle::Circle(Vec2 const& ctr, float r, Color const& clr) :
    center_{ctr},
    radius_{r},
    color_{clr} {}

void Circle::center(Vec2 const& ctr){   //getter
    center_ = ctr;
}
void Circle::radius(float r){
    radius_ = r;
}

float Circle::radius() const{           //setter        
    return radius_;
}

Vec2 Circle::center() const{
    return center_;
}

float Circle::circumference() const{
    return 2 * M_PI * radius_;
}

//2.11
void Circle::draw(Window const& w) const {
    draw(w, color_);
}

//2.12
void Circle::draw(Window const& w, Color const& clr) const {
    float a = 32.0;
    for(int i = 0; i < a; ++i){

        w.draw_line( center_.x + radius_ * sin( (2 * M_PI / a) * i),
                     center_.y + radius_ * cos( (2 * M_PI / a) * i),
                     center_.x + radius_ * sin( (2 * M_PI / a) * (i+1)),
                     center_.y + radius_ * cos( (2 * M_PI / a) * (i+1)),
                     clr.r, clr.g, clr.b);
    }
}

//2.13
bool Circle::is_inside(Vec2 const& p) {
  //(x-center_x)^2 + (y - center_y)^2 < radius^2
  if (abs(pow(p.x - center_.x,2)) + (pow(p.y - center_.y,2)) <= pow(radius_,2)){
        return true;
  }
  else{
        return false;
  }
}

//3.6

bool operator<(Circle const& c1, Circle const& c2){
    return c1.radius() < c2.radius();
}

bool operator>(Circle const& c1, Circle const& c2){
    return c1.radius() > c2.radius();
}
bool operator==(Circle const& c1, Circle const& c2){
    return c1.radius() == c2.radius();
}
