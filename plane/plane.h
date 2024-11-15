#pragma once

#include "../line/line.h"

class Plane_t final{
private:
    Vector_t vector;
    float distance;

public:
    Plane_t(Triangle_t triangle);
    Plane_t(Vector_t v, float d): 
            vector(v), distance(d) {};
    Plane_t(float vx, float vy, float vz, float d): 
            vector(vx, vy, vz), distance(d) {};

    Vector_t get_v() const;
    float    get_d() const;

    bool operator==(Plane_t plane) const;

    bool  planes_match(Plane_t& plane)               const;
    float put_point_in_equation(Point_t point)       const;
    bool  vertices_on_one_side(Triangle_t& triangle) const;
    bool  vertices_on_plane(Triangle_t& triangle)    const;
};

