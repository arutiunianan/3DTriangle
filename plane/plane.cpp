#include "plane.h"

/*
|  i    j    k  |
| abx  aby  abz | = n - the normal vector of the plane
| aсx  acy  acz |
*/
Plane_t::Plane_t(Triangle_t triangle) {
    Vector_t ab(triangle.get_a(),  triangle.get_b());
    Vector_t ac(triangle.get_a(),  triangle.get_c());
    vector = cross(ab, ac);
    distance = vector.get_x() * (-triangle.get_a().get_x()) + 
               vector.get_y() * (-triangle.get_a().get_y()) + 
               vector.get_z() * (-triangle.get_a().get_z());
}

Vector_t Plane_t::get_v() const {
    return vector;
}
float Plane_t::get_d() const {
    return distance;
}

bool Plane_t::operator==(Plane_t plane) const {
    return (vector.get_x() == plane.get_v().get_x()) &&
           (vector.get_y() == plane.get_v().get_y()) &&
           (vector.get_z() == plane.get_v().get_z()) &&
           (distance == plane.get_d());
}

bool Plane_t::planes_match(Plane_t& plane) const {
    if(distance == 0 && plane.get_d() == 0) {
        return true;
    }
    if(vector == 0 && plane.get_v() == 0) {
        return true;
    }
    if((vector.get_x() / plane.vector.get_x()) == 
        (distance / plane.get_d())) {
        return true;
    }
    return false;
}

float Plane_t::put_point_in_equation(Point_t point) const {
    return (point.get_x() * vector.get_x() + 
            point.get_y() * vector.get_y() + 
            point.get_z() * vector.get_z() + distance);
}

bool Plane_t::vertices_on_one_side(Triangle_t& triangle) const {
    if(put_point_in_equation(triangle.get_a()) > 0 &&
       put_point_in_equation(triangle.get_b()) > 0 &&
       put_point_in_equation(triangle.get_c()) > 0) {
       return true;
    }
    if(put_point_in_equation(triangle.get_a()) < 0 &&
       put_point_in_equation(triangle.get_b()) < 0 &&
       put_point_in_equation(triangle.get_c()) < 0) {
       return true;
    }
    return false;
}

bool Plane_t::vertices_on_plane(Triangle_t& triangle) const {
    return (put_point_in_equation(triangle.get_a()) == 0) &&
           (put_point_in_equation(triangle.get_b()) == 0) &&
           (put_point_in_equation(triangle.get_c())== 0);
}