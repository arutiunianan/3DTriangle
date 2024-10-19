#include "vector.h"
#include <cmath>

Vector_t Vector_t::operator+(Vector_t vector) {
    Vector_t new_vector(x + vector.x, y + vector.y, z + vector.z);
    return new_vector;
}

Vector_t Vector_t::operator-(Vector_t vector) {
    Vector_t new_vector(x - vector.x, y - vector.y, z - vector.z);
    return new_vector;
}

Vector_t Vector_t::operator-() {
    Vector_t new_vector(-x, -y, -z);
    return new_vector;
}

Vector_t Vector_t::operator*(float value) {
    Vector_t new_vector(x * value, y * value, z * value);
    return new_vector;
}

Vector_t Vector_t::operator/(float value) {
    Vector_t new_vector(x / value, y / value, z / value);
    return new_vector;
}

Vector_t Vector_t::operator/(Vector_t vector) {
    Vector_t new_vector(x / vector.x, y / vector.y, z / vector.z);
    return new_vector;
}

Vector_t Vector_t::operator=(Point_t point) {
    x = point.x;
    y = point.y;
    z = point.z;
    return *this;
}

bool Vector_t::operator==(float value) {
    if(x == value && y == value && z == value) {
        return true;
    }
    return false;
}

float Vector_t::length() {
    return sqrt(x * x + y * y + z * z);
}

Vector_t cross(Vector_t v1, Vector_t v2) {
    Vector_t new_v(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x *v2.z, v1.x * v2.y - v1.y * v2.x);
    return new_v;
}

float dot(Vector_t v1, Vector_t v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float dot(Vector_t v1, Point_t p2) {
    return v1.x * p2.x + v1.y * p2.y + v1.z * p2.z;
}