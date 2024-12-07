#pragma once

#include <iostream>
#include <list>
#include <vector>

class Vector_t;
class Triangle_t;
class Line_t;

class Point_t final {
private:
    double x;
    double y;
    double z;

public:
    Point_t(): x(0), y(0), z(0) {};
    Point_t(double x_, double y_, double z_): 
            x(x_), y(y_), z(z_) {};
    Point_t(Line_t& line, double t);
    Point_t(Triangle_t& triangle);
    
    double get_x() const;
    double get_y() const;
    double get_z() const;

    Point_t operator+(Point_t point)  const;
    Point_t operator-(Point_t point)  const;
    Point_t operator*(double value)   const;
    Point_t operator=(Vector_t vector);
    bool    operator==(Point_t point) const;
    double  operator[](int i)         const;

    void print() const;
};