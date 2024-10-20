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

bool Point_t::operator==(Point_t point) {
    return (x == point.x && y == point.y && z == point.z);
}

Point_t Point_t::operator=(Vector_t vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

void Point_t::print() {
    std::cout << x << " " << y << " " << z << std::endl;
}