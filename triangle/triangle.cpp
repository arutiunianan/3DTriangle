#include "../line/line_segment.h"
#include <float.h>

bool Triangle_t::is_point() {
    return (a == b && c == b);
}

bool Triangle_t::is_segment() {
    Vector_t AB(a, b);
    Vector_t AC(a, c);
    return cross(AB, AC) == 0;
}

float Triangle_t::triangle_square() {
    Vector_t AB(a, b);
    Vector_t AC(a, c);
    return 0.5 * cross(AB, AC).length();
}

void Triangle_t::check_triangle_type() {
    if(is_point()) {
        type = IS_POINT;
        return;
    }
    if(is_segment()) {
        type = IS_SEGMENT;
        return;
    }
    type = IS_TRIANGLE;
}

Point_t Triangle_t::operator[](int i) {
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