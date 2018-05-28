#define CATCH_CONFIG_RUNNER 
#include <catch.hpp> 
#include <cmath>
#include <algorithm>
#include "circle.hpp"



bool is_multiple_of_3(unsigned int i){
    return (i % 3) == 0  && i != 0;
}
bool is_not_multiple_of_3(unsigned int i){
    return !is_multiple_of_3(i);
}

TEST_CASE("filter alle vielfache von drei", "[erase]") {

    srand(time(NULL));

    std::vector<unsigned int> v(100);
    auto random = [] () -> unsigned int { return rand() % 101;};
    
    std::generate(v.begin(), v.end(), random);

    v.erase( std::remove_if( v.begin(), v.end(), is_not_multiple_of_3 ), v.end() ); 

    REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3)); 
}


//////////////////3.12///////////////////////

TEST_CASE("aufgabe12", "[aufgabe12]"){
    std::vector<int> v_1{1,2,3,4,5,6,7,8,9}; 
    std::vector<int> v_2{9,8,7,6,5,4,3,2,1}; 
    std::vector<int> v_3(9);

    auto lambda = [](int a, int b)-> int {
        return a + b;
    };

    std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(), lambda);

    REQUIRE(std::all_of(v_3.begin(), v_3.end(),[](int a)-> bool {return a == 10;})); 

}


//////////////////////3.14//////////////////////

TEST_CASE("aufgabe14", "[aufgabe14]"){
    std::vector<Circle> circles{{Vec2{},5.0f, Color{}},
                                {Vec2{},3.0f, Color{}},
                                {Vec2{},8.0f, Color{}},
                                {Vec2{},1.0f, Color{}},
                                {Vec2{},5.0f, Color{}}};
    std::vector<Circle> c;

    auto lambda = [](Circle a)-> bool {
        return a.radius() > 4.0f;
    };

    std::copy_if(circles.begin(), circles.end(),  std::back_inserter(c), lambda);

    REQUIRE(std::all_of(c.begin(), c.end(),[](Circle a)-> bool {return a.radius() > 4.0f;}));                          
}





int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv); 
}