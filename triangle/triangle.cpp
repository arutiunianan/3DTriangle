#include "../line/line_segment.h"
#include <float.h>

Point_t Triangle_t::get_a() const {
    return a;
}
Point_t Triangle_t::get_b() const {
    return b;
}
Point_t Triangle_t::get_c() const {
    return c;
}
Triangle_type Triangle_t::get_type() const {
    return type;
}

bool Triangle_t::is_point() const {
    return (a == b && c == b);
}

bool Triangle_t::is_segment() const {
    Vector_t AB(a, b);
    Vector_t AC(a, c);
    return cross(AB, AC) == 0;
}

float Triangle_t::triangle_square() const {
    Vector_t AB(a, b);
    Vector_t AC(a, c);
    return 0.5 * cross(AB, AC).length();
}

bool Triangle_t::check_triangle_type() {
    if(is_point()) {
        type = IS_POINT;
        return false;
    }
    if(is_segment()) {
        type = IS_SEGMENT;
        return false;
    }
    type = IS_TRIANGLE;
    return true;
}

Point_t Triangle_t::operator[](int i) const {
    if(i == 0) {
        return a;
    }
    if(i == 1) {
        return b;
    }
    if(i == 2) {
        return c;
    }
    if(i == 3) {
        return a;
    }
}

void Triangle_t::print() const {
    a.print();
    b.print();
    c.print();
    std::cout << type << std::endl;
}