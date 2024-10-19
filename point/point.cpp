#include "../vector/vector.h"

Point_t Point_t::operator+(Point_t point) {
    Point_t new_point(x + point.x, y + point.y, z + point.z);
    return new_point;
}

Point_t Point_t::operator-(Point_t point) {
    Point_t new_point(x - point.x, y - point.y, z - point.z);
    return new_point;
}

Point_t Point_t::operator=(Vector_t vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}