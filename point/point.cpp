#include "../line/line_segment.h"

Point_t::Point_t(Line_t& line, float t):
        x(line.get_p().get_x() + line.get_v().get_x() * t), 
        y(line.get_p().get_y() + line.get_v().get_y() * t), 
        z(line.get_p().get_z() + line.get_v().get_z() * t) {}

Point_t::Point_t(Triangle_t& triangle):
        x(triangle.get_a().get_x()),
        y(triangle.get_a().get_y()), 
        z(triangle.get_a().get_z()) {};

float Point_t::get_x() const {
    return x;
}
float Point_t::get_y() const {
    return y;
}
float Point_t::get_z() const {
    return z;
}

Point_t Point_t::operator+(Point_t point) const {
    Point_t new_point(x + point.x, y + point.y, z + point.z);
    return new_point;
}

Point_t Point_t::operator-(Point_t point) const {
    Point_t new_point(x - point.x, y - point.y, z - point.z);
    return new_point;
}

Point_t Point_t::operator*(float value) const {
    Point_t new_point(x * value, y * value, z * value);
    return new_point;
}

bool Point_t::operator==(Point_t point) const {
    return (x == point.x && y == point.y && z == point.z);
}

Point_t Point_t::operator=(Vector_t vector) {
    x = vector.get_x();
    y = vector.get_y();
    z = vector.get_z();
    return *this;
}

float Point_t::operator[](int i) const {
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

void Point_t::print() const {
    std::cout << x << " " << y << " " << z << std::endl;
}