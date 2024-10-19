#pragma once
#include "../point/point.h"

struct Vector_t {
    float x;
    float y;
    float z;

    Vector_t(): x(0), y(0), z(0) {};
    Vector_t(float x_, float y_, float z_): 
            x(x_), y(y_), z(z_) {};
    Vector_t(Point_t point1, Point_t point2): 
            x(point2.x - point1.x), y(point2.y - point1.y), z(point2.z - point1.z) {};

    Vector_t operator+(Vector_t vector);
    Vector_t operator-(Vector_t vector);
    Vector_t operator-();
    Vector_t operator*(float value);
    Vector_t operator/(float value);
    Vector_t operator/(Vector_t vector);
    Vector_t operator=(Point_t point);
    bool     operator==(float value);
    float    length();
};

float dot(Vector_t v1, Vector_t v2);
float dot(Vector_t v1, Point_t p2);
Vector_t cross(Vector_t v1, Vector_t v2);