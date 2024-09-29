#include <iostream>
#include <list>
#include <vector>

struct Point_t {
    float x;
    float y;
    float z;

    Point_t(float x_, float y_, float z_): 
            x(x_), y(y_), z(z_) {};
        
    Point_t operator+(Point_t point);
    Point_t operator-(Point_t point);
};