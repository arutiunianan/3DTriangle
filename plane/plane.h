#pragma once
#include "../line/line.h"

struct Plane_t {
    Vector_t vector;
    float distance;

    Plane_t(Triangle_t triangle);
    Plane_t(Vector_t vector_, float distance_): vector(vector_), distance(distance_) {};

    bool planes_match(Plane_t& plane);

    float put_point_in_equation(Point_t& point);
    bool vertices_on_one_side(Triangle_t& triangle);
    bool vertices_on_plane(Triangle_t& triangle);
};

