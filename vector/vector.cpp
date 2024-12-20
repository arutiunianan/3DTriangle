#include "vector.h"
#include <cmath>

const double DOUBLE_TOLERANCE = 1e-9;

double Vector_t::get_x() const {
    return x;
}
double Vector_t::get_y() const {
    return y;
}
double Vector_t::get_z() const {
    return z;
}

Vector_t Vector_t::operator+(Vector_t vector) const {
    Vector_t new_vector(x + vector.x, y + vector.y, z + vector.z);
    return new_vector;
}

Vector_t Vector_t::operator-(Vector_t vector) const {
    Vector_t new_vector(x - vector.x, y - vector.y, z - vector.z);
    return new_vector;
}

Vector_t Vector_t::operator-() const {
    Vector_t new_vector(-x, -y, -z);
    return new_vector;
}

Vector_t Vector_t::operator*(double value) const {
    Vector_t new_vector(x * value, y * value, z * value);
    return new_vector;
}

Vector_t Vector_t::operator/(double value) const {
    Vector_t new_vector(x / value, y / value, z / value);
    return new_vector;
}

Vector_t Vector_t::operator/(Vector_t vector) const {
    Vector_t new_vector(x / vector.x, y / vector.y, z / vector.z);
    return new_vector;
}

Vector_t Vector_t::operator=(Point_t point) {
    x = point.get_x();
    y = point.get_y();
    z = point.get_z();
    return *this;
}

bool Vector_t::operator==(double value) const {
    if(value == 0) {
        return std::abs(x) < DOUBLE_TOLERANCE && 
               std::abs(y) < DOUBLE_TOLERANCE && 
               std::abs(z) < DOUBLE_TOLERANCE;
    }
    if(x == value && y == value && z == value) {
        return true;
    }
    return false;
}

bool Vector_t::operator==(Vector_t vector) const {
    if(x == vector.get_x() && 
       y == vector.get_y() && 
       z == vector.get_z()) {
        return true;
    }
    return false;
}

double Vector_t::operator[](int i) const {
    if(i == 0) {
        return x;
    }
    if(i == 1) {
        return y;
    }
    if(i == 2) {
        return z;
    }
}

double Vector_t::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector_t cross(Vector_t v1, Vector_t v2) {
    Vector_t new_v(v1.get_y() * v2.get_z() - v1.get_z() * v2.get_y(), 
                   v1.get_z() * v2.get_x() - v1.get_x() * v2.get_z(), 
                   v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x());
    return new_v;
}

double dot(Vector_t v1, Vector_t v2) {
    return v1.get_x() * v2.get_x() + 
           v1.get_y() * v2.get_y() + 
           v1.get_z() * v2.get_z();
}

double dot(Vector_t v1, Point_t p2) {
    return v1.get_x() * p2.get_x() + 
           v1.get_y() * p2.get_y() + 
           v1.get_z() * p2.get_z();
}

void Vector_t::print() const {
    std::cout << x << " " << y << " " << z << std::endl;
}