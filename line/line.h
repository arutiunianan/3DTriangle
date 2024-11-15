#pragma once
#include "../triangle/triangle.h"

struct Plane_t; 

struct Line_t {
    Vector_t vector;
    Point_t point;

    Line_t(): vector(), point() {};
    Line_t(Vector_t v, Point_t p): vector(v), point(p) {};
    Line_t(Point_t p1, Point_t p2): vector(Vector_t{p1, p2}), point(p1) {};
    Line_t(std::pair <Point_t, Point_t> ps): vector(Vector_t{ps.first, 
                                                             ps.second}), 
                                             point(ps.first) {};
    Line_t(Plane_t& plane1, Plane_t& plane2);

    float get_t(Point_t p);
    bool lines_match(Line_t& line);
};