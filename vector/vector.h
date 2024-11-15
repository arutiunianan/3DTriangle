#pragma once

#include "../point/point.h"

class Vector_t final {
private:
    float x;
    float y;
    float z;

public:
    Vector_t(): x(0), y(0), z(0) {};
    Vector_t(float x_, float y_, float z_): 
            x(x_), y(y_), z(z_) {};
    Vector_t(Point_t point1, Point_t point2): 
            x(point2.get_x() - point1.get_x()), 
            y(point2.get_y() - point1.get_y()), 
            z(point2.get_z() - point1.get_z()) {};

    float get_x() const;
    float get_y() const;
    float get_z() const;

    Vector_t operator+(Vector_t vector) const;
    Vector_t operator-(Vector_t vector) const;
    Vector_t operator-()                const;
    Vector_t operator*(float value)     const;
    Vector_t operator/(float value)     const;
    Vector_t operator/(Vector_t vector) const;
    Vector_t operator=(Point_t point);
    bool     operator==(float value)     const;
    bool     operator==(Vector_t vector) const;
    float    operator[](int i)           const;

    float    length() const;
    void     print()  const;
};

float    dot(Vector_t v1, Vector_t v2);
float    dot(Vector_t v1, Point_t p2);
Vector_t cross(Vector_t v1, Vector_t v2);