#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

TEST_CASE("aufgabe2.2","[aufgabe2.2]") {
    Vec2 ohne = Vec2{};
    REQUIRE(ohne.x == 0); 
    REQUIRE(ohne.y == 0);

    Vec2 mit = Vec2{3.3,4.4};
    REQUIRE(mit.x == Approx(3.3)); 
    REQUIRE(mit.y == Approx(4.4));
}

TEST_CASE("aufgabe2.3","[aufgabe2.3]"){
    Vec2 a = Vec2{3.0, 4.0};
    a += Vec2{1.0, 1.0};
    REQUIRE(a.x == Approx(4.0)); 
    REQUIRE(a.y == Approx(5.0));
    a -= Vec2{1.0, 1.0};
    REQUIRE(a.x == Approx(3.0)); 
    REQUIRE(a.y == Approx(4.0));
    a *= 2.0;
    REQUIRE(a.x == Approx(6.0)); 
    REQUIRE(a.y == Approx(8.0));
    a /= 2.0;
    REQUIRE(a.x == Approx(3.0)); 
    REQUIRE(a.y == Approx(4.0));
}

TEST_CASE("aufgabe2.4","[aufgabe2.4]"){
  Vec2 b = Vec2{6.0,3.0};
  Vec2 c = Vec2{3.0,2.0};
  float s = 3.0;
  Vec2 d;
  d = b + c;
  REQUIRE(d.x == Approx(9.0)); 
  REQUIRE(d.y == Approx(5.0));
  d = b - c;
  REQUIRE(d.x == Approx(3.0)); 
  REQUIRE(d.y == Approx(1.0));
  d = b * s;
  REQUIRE(d.x == Approx(18.0)); 
  REQUIRE(d.y == Approx(9.0));
  d = b / s;
  REQUIRE(d.x == Approx(2.0)); 
  REQUIRE(d.y == Approx(1.0));
  d = s * b;
  REQUIRE(d.x == Approx(18.0)); 
  REQUIRE(d.y == Approx(9.0));
}

TEST_CASE("aufgabe2.5","[aufgabe2.5]"){
  Mat2 m1 = Mat2{1.0,2.0,3.0,4.0};
  Mat2 m2 = Mat2{2.0,8.0,3.0,5.0};
  Mat2 m3;
   
  m3 = m1 * m2;
  REQUIRE(m3.a == Approx(8.0)); 
  REQUIRE(m3.b == Approx(18.0));
  REQUIRE(m3.c == Approx(18.0)); 
  REQUIRE(m3.d == Approx(44.0));
  
  
  m1 *= m2;
  REQUIRE(m1.a == Approx(8.0)); 
  REQUIRE(m1.b == Approx(18.0));
  REQUIRE(m1.c == Approx(18.0)); 
  REQUIRE(m1.d == Approx(44.0));

  Mat2 m4 = Mat2{2.0,4.0,8.0,16.0};
  Mat2 m5 = Mat2{0.0,2.0,3.0,8.0};
  Mat2 m6;
  m6 = m4 * m5;
  REQUIRE(m6.a == Approx(12.0)); 
  REQUIRE(m6.b == Approx(36.0));
  REQUIRE(m6.c == Approx(48.0)); 
  REQUIRE(m6.d == Approx(144.0));

  m4 *= m5;
  REQUIRE(m1.a == Approx(8.0)); 
  REQUIRE(m1.b == Approx(18.0));
  REQUIRE(m1.c == Approx(18.0)); 
  REQUIRE(m1.d == Approx(44.0));

}

TEST_CASE("aufgabe2.6","[aufgabe2.6]"){
  Mat2 m1 = Mat2{1.0,2.0,3.0,4.0};
  Mat2 m2 = Mat2{2.0,4.0,3.0,6.0};
  Mat2 m3 = Mat2{2.0,-4.0,3.0,6.0};
  Mat2 m4;

  Vec2 v1 = Vec2{3.0,4.0};
  Vec2 v2 = Vec2{5.0,0.0};
  Vec2 v3;

  REQUIRE(m1.det()==Approx(10));
  REQUIRE(m2.det()==Approx(24));
  v3 = m1 * v1;
  REQUIRE(v3.x == Approx(11.0)); 
  REQUIRE(v3.y == Approx(25.0));
  v3 = m2 * v2;
  REQUIRE(v3.x == Approx(10.0)); 
  REQUIRE(v3.y == Approx(15.0));
  v3 = v1 * m2;
  REQUIRE(v3.x == Approx(22.0)); 
  REQUIRE(v3.y == Approx(33.0));
  v3 = v2 * m1;
  REQUIRE(v3.x == Approx(5.0)); 
  REQUIRE(v3.y == Approx(15.0));
  
  m4 = inverse(m1);
  REQUIRE(m4.a == Approx(-2));
  REQUIRE(m4.b == Approx(1));
  REQUIRE(m4.c == Approx(1.5));
  REQUIRE(m4.d == Approx(-0.5));

  m4 = inverse(m3);
  REQUIRE(m4.a == Approx(0.25));
  REQUIRE(m4.b == Approx(0.16666666666));
  REQUIRE(m4.c == Approx(-0.125));
  REQUIRE(m4.d == Approx(0.08333333333));

  m4 = transpose(m1);
  REQUIRE(m4.a == Approx(1));
  REQUIRE(m4.b == Approx(3));
  REQUIRE(m4.c == Approx(2));
  REQUIRE(m4.d == Approx(4));

   m4 = transpose(m2);
  REQUIRE(m4.a == Approx(2));
  REQUIRE(m4.b == Approx(3));
  REQUIRE(m4.c == Approx(4));
  REQUIRE(m4.d == Approx(6));

  m4 = make_rotation_mat2(30);
  REQUIRE(m4.a == Approx(0.15425144988));
  REQUIRE(m4.b == Approx(-0.98803162409));
  REQUIRE(m4.c == Approx(0.98803162409));
  REQUIRE(m4.d == Approx(0.15425144988));
}

TEST_CASE("aufgabe2.8","[aufgabe2.8]"){
  Circle c1 = Circle{Vec2{0.0, 1.0},2.0,Color{0.0,0.0,1.0}};
  
  REQUIRE(c1.radius() == Approx(2.0));
  REQUIRE(c1.center().x == Approx(0.0));
  REQUIRE(c1.center().y == Approx(1.0));
  
  Rectangle r1 = Rectangle{Vec2{2.0,3.0},Vec2{4.0,5.0},Color{0.0,0.0,1.0}};
  Rectangle r2 = Rectangle{Vec2{1.0,1.0},Vec2{4.0,6.0},Color{0.0,0.0,1.0}};
  REQUIRE(r1.min().x == Approx(2.0));
  REQUIRE(r1.min().y == Approx(3.0));
  REQUIRE(r1.max().x == Approx(4.0));
  REQUIRE(r1.max().y == Approx(5.0));

  REQUIRE(c1.circumference() == Approx(12.5663706144));
  REQUIRE(r1.circumference() == Approx(8));
  REQUIRE(r2.circumference() == Approx(16));
}

TEST_CASE("aufgabe2.13","[aufgabe2.13]"){
  Vec2 p1 = Vec2{3.0, 4.0};
  Vec2 p2 = Vec2{6.0, 7.0};
  Vec2 p3 = Vec2{13.0,18.0};
  Rectangle r1 = Rectangle{Vec2{2.0,3.0},Vec2{4.0,5.0},Color{0.0,0.0,1.0}};
  REQUIRE(r1.is_inside(p1) == true);
  REQUIRE(r1.is_inside(p2) == false);
  Circle c1 = Circle{Vec2{0.0, 1.0},10.0,Color{0.0,0.0,1.0}};
  REQUIRE(c1.is_inside(p1) == true);
  REQUIRE(c1.is_inside(p3) == false);
}