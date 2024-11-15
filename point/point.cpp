#include "../line/line_segment.h"

Point_t::Point_t(Line_t& line, float t):
        x(line.point.x + line.vector.x * t), 
        y(line.point.y + line.vector.y * t), 
        z(line.point.z + line.vector.z * t) {}

Point_t::Point_t(Triangle_t& triangle):
            x(triangle.a.x), y(triangle.a.y), z(triangle.a.z) {};

Point_t Point_t::operator+(Point_t point) {
    Point_t new_point(x + point.x, y + point.y, z + point.z);
    return new_point;
}

Point_t Point_t::operator-(Point_t point) {
    Point_t new_point(x - point.x, y - point.y, z - point.z);
    return new_point;
}

Point_t Point_t::operator*(float value) {
    Point_t new_point(x * value, y * value, z * value);
    return new_point;
}

bool Point_t::operator==(Point_t point) {
    return (x == point.x && y == point.y && z == point.z);
}

Point_t Point_t::operator=(Vector_t vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

float Point_t::operator[](int i) {
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

void Point_t::print() {
    std::cout << x << " " << y << " " << z << std::endl;
}