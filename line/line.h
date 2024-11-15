#pragma once

#include "../triangle/triangle.h"

class Plane_t; 

class Line_t final {
private:
    Vector_t vector;
    Point_t point;

public:
    Line_t(): vector(), point() {};
    Line_t(Vector_t v, Point_t p): 
           vector(v), point(p) {};
    Line_t(Point_t p1, Point_t p2):
           vector(Vector_t{p1, p2}), point(p1) {};
    Line_t(std::pair <Point_t, Point_t> ps): 
           vector(Vector_t{ps.first, ps.second}), 
           point(ps.first) {};
    Line_t(Plane_t& plane1, Plane_t& plane2);

    Vector_t get_v() const;
    Point_t  get_p() const;

    float get_t(Point_t p) const;
    bool lines_match(Line_t& line) const;
};