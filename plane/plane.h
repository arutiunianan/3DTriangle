#pragma once

#include "../line/line.h"

class Plane_t final{
private:
    Vector_t vector;
    double   distance;

public:
    Plane_t(Triangle_t triangle);
    Plane_t(Vector_t v, double d): 
            vector(v), distance(d) {};
    Plane_t(double vx, double vy, double vz, double d): 
            vector(vx, vy, vz), distance(d) {};

    Vector_t get_v() const;
    double   get_d() const;

    bool operator==(Plane_t plane) const;

    bool   planes_match(Plane_t& plane)               const;
    double put_point_in_equation(Point_t point)       const;
    bool   vertices_on_one_side(Triangle_t& triangle) const;
    bool   vertices_on_plane(Triangle_t& triangle)    const;
};

