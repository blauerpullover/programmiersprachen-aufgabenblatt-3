#include "mat2.hpp"
#include "vec2.hpp"
#include <math.h>

//2.5
Mat2::Mat2() : a{1.0f}, b{0.0f}, c{0.0f}, d{1.0f}{}

Mat2::Mat2(float m_a, float m_b, float m_c, float m_d) :
    a{m_a},
    b{m_b},
    c{m_c},
    d{m_d} {}

Mat2& Mat2::operator*=( Mat2 const & m){
    float old_a = a;
    float old_c = c;
    
    a = a * m.a + b * m.c;
    b = old_a * m.b + b * m.d;
    c = c * m.a + d * m.c;
    d = old_c * m.b + d * m.d;

    return *this;
}

Mat2 operator*( Mat2 const & m1 , Mat2 const & m2 ){
    return Mat2{m1} *= m2;
}

//2.6
float Mat2::det() const{
    return a * d + c * b;
}

Vec2 operator*(Mat2 const & m,Vec2 const & v){
    float x = m.a * v.x + m.b * v.y;
    float y = m.c * v.x + m.d * v.y;
    return  Vec2{x,y};
}

Vec2 operator *(Vec2 const & v,Mat2 const & m){
    return Mat2{m} * Vec2{v};
}

Mat2 inverse(Mat2 const & m){
    float x = 1.0 / (m.a * m.d - m.b * m.c);
    float a = x * m.d;
    float b = x * -m.b;
    float c = x * -m.c;
    float d = x * m.a;
    return Mat2{a,b,c,d};
}

Mat2 transpose(Mat2 const & m){
    float a = m.a;
    float b = m.c;
    float c = m.b;
    float d = m.d;
    return Mat2{a,b,c,d};
}

Mat2 make_rotation_mat2(float phi){ //mit dem Uhrzeigersinn
    float a = cos(phi);
    float b = sin(phi);
    float c = -sin(phi);
    float d = cos(phi);
    return Mat2{a,b,c,d};
}