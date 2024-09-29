#include "point.h"

Point_t Point_t::operator+(Point_t point) {
    Point_t new_point(x + point.x, y + point.y, z + point.z);
    return new_point;
}

Point_t Point_t::operator-(Point_t point) {
    Point_t new_point(x - point.x, y - point.y, z - point.z);
    return new_point;
}