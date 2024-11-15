#pragma once

#include "../vector/vector.h"

enum Triangle_type {
    NO_SHAPE,
    IS_POINT,
    IS_SEGMENT,
    IS_TRIANGLE
};

class Triangle_t {
private:
    Point_t a;
    Point_t b;
    Point_t c;
    Triangle_type type = NO_SHAPE;

public:
    Triangle_t(Point_t a_, Point_t b_, Point_t c_): 
            a(a_), b(b_), c(c_) {};

    Point_t get_a() const;
    Point_t get_b() const;
    Point_t get_c() const;

    Point_t operator[](int i) const;

    Triangle_type get_type() const;
    bool          check_triangle_type();

    bool is_point()   const;
    bool is_segment() const;

    float triangle_square() const;
};

bool check_intersection(Triangle_t& comparison_triangle1, 
                        Triangle_t& comparison_triangle2);