#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include "circle.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

TEST_CASE("aufgabe_6","[aufgabe_6]") {

    std::vector<Circle> sorted_circles;

    sorted_circles.push_back(Circle{Vec2{10,3}, 7, Color{1,1,0.2}});
    sorted_circles.push_back(Circle{Vec2{10,3}, 13, Color{1,1,0.2}});
    sorted_circles.push_back(Circle{Vec2{10,3}, 4, Color{1,1,0.2}});

    std::sort(sorted_circles.begin(), sorted_circles.end());
    
    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

TEST_CASE("aufgabe_7","[aufgabe_7]") {

    std::vector<Circle> sorted_circles;

    sorted_circles.push_back(Circle{Vec2{10,3}, 7, Color{1,1,0.2}});
    sorted_circles.push_back(Circle{Vec2{10,3}, 13, Color{1,1,0.2}});
    sorted_circles.push_back(Circle{Vec2{10,3}, 4, Color{1,1,0.2}});

   auto lambda = [](Circle const& a, Circle const& b)-> bool {
    return a.radius() < b.radius();
   };

    std::sort(sorted_circles.begin(), sorted_circles.end(), lambda);
    
    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));

}


class less_circle {
    public:
        bool operator() (Circle const& a, Circle const& b) {
            return a.radius() < b.radius();
        }
};

TEST_CASE("aufgabe_8","[aufgabe_8]") {

    std::vector<Circle> sorted_circles;

    sorted_circles.push_back(Circle{Vec2{10,3}, 7, Color{1,1,0.2}});
    sorted_circles.push_back(Circle{Vec2{10,3}, 13, Color{1,1,0.2}});
    sorted_circles.push_back(Circle{Vec2{10,3}, 4, Color{1,1,0.2}});

    std::sort(sorted_circles.begin(), sorted_circles.end(), less_circle{});
    
    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));


}
