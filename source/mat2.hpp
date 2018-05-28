#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

struct Mat2 {
    float a;
    float b;
    float c;
    float d;

    Mat2();
    Mat2(float m_a, float m_b, float m_c, float m_d);

    Mat2&operator*=( Mat2 const & m);

    float det() const;
};

Mat2 operator*( Mat2 const & m1 , Mat2 const & m2 );

Vec2 operator*(Mat2 const & m,Vec2 const & v);
Vec2 operator *(Vec2 const & v,Mat2 const & m);
Mat2 inverse(Mat2 const & m);
Mat2 transpose(Mat2 const & m);
Mat2 make_rotation_mat2(float phi);

#endif // MAT2_HPP

