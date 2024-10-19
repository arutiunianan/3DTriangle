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

float triangle_square(Point_t& a, Point_t& b, Point_t& c) {
    Vector_t AB(a, b);
    Vector_t AC(a, c);
    return 0.5 * cross(AB, AC).length();
}

bool point_check(Point_t& point, Triangle_t& triangle) {
    float SABC = triangle_square(triangle.a, triangle.b, triangle.c);
    float SABP = triangle_square(triangle.a, triangle.b, point);
    float SAPC = triangle_square(triangle.a, point, triangle.c);
    float SPBC = triangle_square(point, triangle.b, triangle.c);
    return std::abs(SABC - SABP - SAPC - SPBC) < 1e-6;;
}

bool segment_check(Triangle_t& segment, Triangle_t& triangle) {
    //Vector_t AB(comparison_triangle1.a, comparison_triangle1.b);
        
    Plane_t plane(triangle);
    if(!plane.vertices_on_one_side(segment)) {
        Line_t intersection_planes_line{segment.a, segment.b};
        Line_segment_t seg{segment, plane, intersection_planes_line};
        Point_t intersection_point(intersection_planes_line, seg.t1);
        return point_check(intersection_point, triangle);
    }
        
    return false;
}

bool check_intersection(Triangle_t comparison_triangle1, 
                        Triangle_t comparison_triangle2) {
    
    if(comparison_triangle1.is_point()) {
        Point_t point(comparison_triangle1);
        return point_check(point, comparison_triangle2);
    }
    if(comparison_triangle2.is_point()) {
        Point_t point(comparison_triangle2);
        return point_check(point, comparison_triangle1);
    }

    if(comparison_triangle1.is_segment()) {
        return segment_check(comparison_triangle1, comparison_triangle2);
    }
    if(comparison_triangle2.is_segment()) {
        return segment_check(comparison_triangle2, comparison_triangle1);
    }

    //the planes in which our triangles are located
    Plane_t plane1(comparison_triangle1);
    Plane_t plane2(comparison_triangle2);

    if(!plane1.vertices_on_one_side(comparison_triangle2) && !plane2.vertices_on_one_side(comparison_triangle1)) {
        if(cross(plane1.vector, plane2.vector) == 0) {
            if(plane1.planes_match(plane2)) {

            }
            return false;

        }
        else {
            Line_t intersection_planes_line{plane1,plane2};
            Line_segment_t seg1{comparison_triangle1, plane2, intersection_planes_line};
            Line_segment_t seg2{comparison_triangle2, plane1, intersection_planes_line};
            return seg1.compare_segments(seg2);
        }
    }
    return false;

    
}