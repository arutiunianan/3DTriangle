#pragma once
#include <iostream>
#include <list>
#include <vector>

struct Vector_t;

struct Point_t {
    float x;
    float y;
    float z;

    Point_t(): x(0), y(0), z(0) {};
    Point_t(float x_, float y_, float z_): 
            x(x_), y(y_), z(z_) {};
        
    Point_t operator+(Point_t point);
    Point_t operator-(Point_t point);
    Point_t operator=(Vector_t vector);// {
    //    Point_t new_point(vector.x, vector.y, vector.z);
    //    return new_point;
    //}
};