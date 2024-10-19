#pragma once
#include "../vector/vector.h"

struct Triangle_t {
    Point_t a;
    Point_t b;
    Point_t c;

    Triangle_t(Point_t a_, Point_t b_, Point_t c_): 
            a(a_), b(b_), c(c_) {};
};

bool check_intersection(Triangle_t comparison_triangle1, 
                        Triangle_t comparison_triangle2);