#include "plane.h"

/*
|  i    j    k  |
| abx  aby  abz | = n - the normal vector of the plane
| abx  acy  acz |
*/
Plane_t::Plane_t(Triangle_t triangle) {
    Vector_t ab(triangle.a,  triangle.b);
    Vector_t ac(triangle.a,  triangle.c);
    Vector_t  n(ab.y * ac.z - ab.z * ac.y, ab.z * ac.x - ab.x * ac.z, ab.x * ac.y - ab.y * ac.x);
    vector = n;
    distance = n.x * (-triangle.a.x) + n.y * (-triangle.a.y) + n.z * (-triangle.a.z);
}