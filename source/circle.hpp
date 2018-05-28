#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <math.h>

class Circle{
    public:
        Circle(Vec2 const& ctr, float r, Color const& clr);
        void center (Vec2 const& ctr);
        Vec2 center() const;
        void radius (float r); //setter
        float radius() const; //getter
        float circumference() const;
        void color(Color const& clr);
        Color color() const;
        void draw(Window  const& w) const;
        void draw(Window const& w, Color const& clr) const;  
        bool is_inside(Vec2 const& p);                                  ////////////////
    private:
        Vec2 center_;
        float radius_;
        Color color_;
        
};


bool operator<(Circle const& c1, Circle const& c2);
bool operator>(Circle const& c1, Circle const& c2);
bool operator==(Circle const& c1, Circle const& c2);

#endif