#include "../triangle/triangle.h"

struct Plane_t {
    Vector_t vector;
    float distance;

    Plane_t(Triangle_t triangle);

    bool is_it_line();
    Line_t planes_intersection_line(Plane_t plane);
};