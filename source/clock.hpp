#ifndef CLOCK_HPP
#define CLOCK_HPP
#include "window.hpp"
#include "circle.hpp"
#include "color.hpp"

class Clock{
    public:
        Clock(Vec2 const& ctr, float r, Color const& clr);

        void center (Vec2 const& ctr);
        Vec2 center() const;
        void radius (float r); //setter
        float radius() const; //getter
        void color(Color const& clr);
        Color color() const;
        void draw(Window  const& w) const;
        void draw(Window const& w, Color const& clr) const; 
        
    
    private:
        Vec2 center_;
        float radius_;
        Color color_;

};


#endif