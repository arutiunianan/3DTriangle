#pragma once
#include "../vector/vector.h"

enum Triangle_type {
    NO_SHAPE,
    IS_POINT,
    IS_SEGMENT,
    IS_TRIANGLE
};

struct Triangle_t {
    Point_t a;
    Point_t b;
    Point_t c;
    Triangle_type type = NO_SHAPE;

    Triangle_t(Point_t a_, Point_t b_, Point_t c_): 
            a(a_), b(b_), c(c_) {};

    Point_t operator[](int i);

    bool check_triangle_type();

    bool is_point();
    bool is_segment();

    float triangle_square();
};

bool check_intersection(Triangle_t comparison_triangle1, 
                        Triangle_t comparison_triangle2);