# ifndef VEC2_HPP
# define VEC2_HPP //um Mehrfachinkludierung zu vermeiden
// Vec2 class definition
struct Vec2     // Datentransferobjekt, vektor des R^2
{
    float x;
    float y;

    Vec2(); //Initialisierungs Liste
    
    Vec2(float n_x, float n_y);


Vec2& operator+=(Vec2 const& v); 
Vec2& operator-=(Vec2 const& v); 
Vec2& operator*=(float s);
Vec2& operator/=(float s);
};

Vec2 operator+(Vec2 const& u, Vec2 const& v); 
Vec2 operator-(Vec2 const& u, Vec2 const& v); 
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& v);




# endif // VEC2_HPP