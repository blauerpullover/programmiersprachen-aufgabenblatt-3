#include "clock.hpp"
#include <math.h>

Clock::Clock(Vec2 const& ctr, float r, Color const& clr) :
    center_{ctr},
    radius_{r},
    color_{clr} {}

void Clock::center(Vec2 const& ctr){   //getter
    center_ = ctr;
}
void Clock::radius(float r){
    radius_ = r;
}

float Clock::radius() const{           //setter        
    return radius_;
}

Vec2 Clock::center() const{
    return center_;
}

void Clock::draw(Window const& w) const {
    float a = 12.0;
    for(int i = 0; i < a; i++){

    w.draw_line( center_.x + radius_ * -sin( (2 * M_PI / a) * i),
                     center_.y + radius_ * cos( (2 * M_PI / a) * i),
                     center_.x + radius_ * -sin( (2 * M_PI / a) * (i+1)),
                     center_.y + radius_ * cos( (2 * M_PI / a) * (i+1)),
                     color_.r,color_.g,color_.b);
    }

    w.draw_line(    center_.x,                                                      //sekunden
                    center_.y,
                    center_.x + 0.9 * radius_ * -sin( M_PI + (2 * M_PI / 60) * w.get_time()),
                    center_.y + 0.9 * radius_ * cos( M_PI + (2 * M_PI / 60) * w.get_time()),
                     0.0,0.2,0.8);
    w.draw_line(    center_.x,                                                      //minuten 
                    center_.y,
                    center_.x + 0.7 * radius_ * -sin( M_PI + (2 * M_PI / 3600) * w.get_time()),
                    center_.y + 0.7 * radius_ * cos( M_PI + (2 * M_PI / 3600) * w.get_time()),
                     0.0,0.6,0.0);
    w.draw_line(   center_.x,                                                      //stunden
                    center_.y,
                    center_.x + 0.5 * radius_ * (-sin(M_PI + (2 * M_PI / 216000) * 10800)),
                    center_.y + 0.5 * radius_ * (cos( M_PI + (2 * M_PI / 216000) * 10800)),
                     0.9,0.0,0.0);

 
}

