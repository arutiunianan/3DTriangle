#pragma once

#include <iostream>
#include <list>
#include <vector>

class Vector_t;
class Triangle_t;
class Line_t;

class Point_t final {
private:
    float x;
    float y;
    float z;

public:
    Point_t(): x(0), y(0), z(0) {};
    Point_t(float x_, float y_, float z_): 
            x(x_), y(y_), z(z_) {};
    Point_t(Line_t& line, float t);
    Point_t(Triangle_t& triangle);
    
    float get_x() const;
    float get_y() const;
    float get_z() const;

    Point_t operator+(Point_t point) const;
    Point_t operator-(Point_t point) const;
    Point_t operator*(float value)   const;
    Point_t operator=(Vector_t vector);
    bool operator==(Point_t point)   const;
    float operator[](int i)          const;

    void print() const;
};