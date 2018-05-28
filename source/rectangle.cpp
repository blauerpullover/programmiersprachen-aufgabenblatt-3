#include "rectangle.hpp"
#include "window.hpp"
#include <math.h>


Rectangle::Rectangle(Vec2 const& mini, Vec2 const& maxi, Color const& clr) :
    min_{mini},
    max_{maxi}, 
    color_{clr}{}

void Rectangle::min(Vec2 const& mini){   //getter
    min_ = mini;
}
void Rectangle::max(Vec2 const& maxi){   //getter
    max_ = maxi;
}
Vec2 const& Rectangle::min() const {
    return min_;
}
Vec2 const& Rectangle::max() const {
    return max_;
}

float Rectangle::circumference() const{
    return abs(2 * (max_.x - min_.x) + 2 * (max_.y - min_.y));
}

//2.11
void Rectangle::draw(Window const& w) const {
    draw(w, color_);
}

//2.12
void Rectangle::draw(Window const& w, Color const& clr) const {
    w.draw_line(min_.x, min_.y,                     //erste Linie
                max_.x, min_.y,
               clr.r, clr.g, clr.b                                                        
                );
    w.draw_line(max_.x, min_.y,                     //zweite Linie
                max_.x, max_.y,
                clr.r, clr.g, clr.b
                );
    w.draw_line(max_.x, max_.y,                     //dritte Linie
                min_.x, max_.y,
                clr.r, clr.g, clr.b
                );
    w.draw_line(min_.x, max_.y,                     //vierte Linie
                min_.x, min_.y,
                clr.r, clr.g, clr.b
                );
}

//2.13
bool Rectangle::is_inside(Vec2 const& p) {
    if(p.x > min_.x && p.y > min_.y && p.x < max_.x && p.y <max_.y){
        return true;
    }
    else{
        return false;                
    }
    
}


