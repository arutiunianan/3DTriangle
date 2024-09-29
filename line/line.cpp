#include "line.h"

Line_t::Line_t(Plane_t plane1, Plane_t plane2) {
    Vector_t new_vector(plane1.vector - plane2.vector);
    vector   = new_vector;
    distance = plane1.distance - plane2.distance;
}