#include "vector.h"

Vector_t Vector_t::operator+(Vector_t vector) {
    Vector_t new_vector(x + vector.x, y + vector.y, z + vector.z);
    return new_vector;
}

Vector_t Vector_t::operator-(Vector_t vector) {
    Vector_t new_vector(x - vector.x, y - vector.y, z - vector.z);
    return new_vector;
}

bool Vector_t::operator==(float value) {
    if(x == value && y == value && z == value) {
        return true;
    }
    return false;
}