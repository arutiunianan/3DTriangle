#pragma once
#include "../triangle/triangle.h"

struct Plane_t; 

struct Line_t {
    Vector_t vector;
    Point_t point;

    Line_t(): vector(), point() {};
    Line_t(Vector_t v, Point_t p): vector(v), point(p) {};
    Line_t(Plane_t& plane1, Plane_t& plane2);
};