#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle{
    public:
        Rectangle(Vec2 const& mini, Vec2 const& maxi, Color const& clr);
        void min(Vec2 const& mini);
        void max(Vec2 const& maxi);
        Vec2 const& min() const;
        Vec2 const& max() const;
        float circumference() const;
        void color(Color const& clr);
        Color color() const;
        void draw(Window const& w) const;             
        void draw(Window const& w, Color const& clr) const;
        bool is_inside(Vec2 const& p);                              //////////////

    private: 
        Vec2 min_;
        Vec2 max_;
        Color color_;
};

#endif