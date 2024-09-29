#include "../plane/plane.h"

struct Line_t {
    Vector_t vector;
    float distance;

    Line_t(Plane_t plane1, Plane_t plane2);
};