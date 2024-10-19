#include "plane.h"

/*
|  i    j    k  |
| abx  aby  abz | = n - the normal vector of the plane
| abx  acy  acz |
*/
Plane_t::Plane_t(Triangle_t triangle) {
    Vector_t ab(triangle.a,  triangle.b);
    Vector_t ac(triangle.a,  triangle.c);
    vector = cross(ab, ac);
    distance = vector.x * (-triangle.a.x) + vector.y * (-triangle.a.y) + vector.z * (-triangle.a.z);
}

bool Plane_t::planes_match(Plane_t& plane) {
    if((vector.x / plane.vector.x) == (distance / plane.distance)) {
        return true;
    }
    return false;
}

float Plane_t::put_point_in_equation(Point_t& point) {
    return (point.x * vector.x + point.y * vector.y + point.z * vector.z + distance);
}

bool Plane_t::vertices_on_one_side(Triangle_t& triangle) {
    if(put_point_in_equation(triangle.a) > 0 &&
       put_point_in_equation(triangle.b) > 0 &&
       put_point_in_equation(triangle.c) > 0) {
       return true;
    }
    if(put_point_in_equation(triangle.a) < 0 &&
       put_point_in_equation(triangle.b) < 0 &&
       put_point_in_equation(triangle.c) < 0) {
       return true;
    }

    return false;
}

bool Plane_t::vertices_on_plane(Triangle_t& triangle) {
    if(put_point_in_equation(triangle.a) == 0 &&
       put_point_in_equation(triangle.b) == 0 &&
       put_point_in_equation(triangle.c)== 0) {
       return true;
    }
    return false;
}