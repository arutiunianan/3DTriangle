#include "../line/line_segment.h"
#include <algorithm>

bool point_point_check(Triangle_t& triangle1, Triangle_t& triangle2) {
    return triangle1.get_a() == triangle2.get_a();
}

bool segment_point_check(Point_t point, Triangle_t segment) {
    Line_t line{segment.get_a(), segment.get_b()};
    float t1 = line.get_t(segment.get_a());
    float t2 = line.get_t(segment.get_b());
    float t3 = line.get_t(segment.get_c());
    float t  = line.get_t(point);
    if(t > t1 && t > t2 && t > t3) {
        return false;
    }
    if(t < t1 && t < t2 && t < t3) {
        return false;
    }
    return true;
}

bool point_triangle_check(Point_t& point, Triangle_t& triangle) {
    float SABC = triangle.triangle_square();
    float SABP = Triangle_t(triangle.get_a(), triangle.get_b(), point).triangle_square();
    float SAPC = Triangle_t(triangle.get_a(), point, triangle.get_c()).triangle_square();
    float SPBC = Triangle_t(point, triangle.get_b(), triangle.get_c()).triangle_square();
    return std::abs(SABC - SABP - SAPC - SPBC) < 1e-6;
}

std::pair<Point_t, Point_t> diff_points(Triangle_t& triangle) {
    if(triangle.get_a() == triangle.get_b()) {
        return std::pair<Point_t, Point_t>(triangle.get_a(), triangle.get_c());
    }
    if(triangle.get_a() == triangle.get_c()) {
        return std::pair<Point_t, Point_t>(triangle.get_a(), triangle.get_b());
    }
    return std::pair<Point_t, Point_t>(triangle.get_b(), triangle.get_c());
}

inline bool check_lines_intersection(Line_t line1, Line_t line2, int i, int j, int k, 
                                     float& t1, float& t2) {
    if(line1.get_v()[i] * line2.get_v()[j] -
       line2.get_v()[i] * line1.get_v()[j] != 0) {
        t2 = ((line1.get_p()[i] - line2.get_p()[i]) * line1.get_v()[j] 
           + (line2.get_p()[j] - line1.get_p()[j]) * line1.get_v()[i])
           / (line2.get_v()[i] * line1.get_v()[j] - line2.get_v()[j] * line1.get_v()[i]);

        t1 = (line2.get_v()[i] * t2 + line2.get_p()[i] - line1.get_p()[i])
            / line1.get_p()[i];

        if((line1.get_v()[k] * t1 + line1.get_p()[k]) != 
           (line2.get_p()[k] * t2 + line2.get_p()[k])) {
            return false;
        }
    }
}

bool segment_segment_check(Triangle_t& triangle1, Triangle_t& triangle2) {
    Line_t line1{diff_points(triangle1)};
    Line_t line2{diff_points(triangle2)};
    
    if(cross(line1.get_v(), line2.get_v()) == 0) {
        if(line1.lines_match(line2)) {
            return true;
        }
        return false;
    }

    float t2 = 0;
    float t1 = 0;
    check_lines_intersection(line1, line2, 0, 1, 2, t1, t2);
    check_lines_intersection(line1, line2, 1, 2, 0, t1, t2);
    check_lines_intersection(line1, line2, 2, 0, 1, t1, t2);

    float min1 = std::min(std::min(line1.get_t(triangle1.get_a()), 
                                   line1.get_t(triangle1.get_b())), 
                                   line1.get_t(triangle1.get_c()));
    
    float max1 = std::max(std::max(line1.get_t(triangle1.get_a()), 
                                   line1.get_t(triangle1.get_b())),
                                   line1.get_t(triangle1.get_c()));

    if(t1 < min1 && t1 > max1) {
        return false;
    }

    float min2 = std::min(std::min(line2.get_t(triangle2.get_a()), 
                                   line2.get_t(triangle2.get_b())), 
                                   line2.get_t(triangle2.get_c()));

    float max2 = std::max(std::max(line2.get_t(triangle2.get_a()), 
                                   line2.get_t(triangle2.get_b())),
                                   line2.get_t(triangle2.get_c()));

    if(t2 < min2 && t2 > max2) {
        return false;
    }

    return true;
}

bool segment_triangle_check(Triangle_t& segment, Triangle_t& triangle) {
    Plane_t plane(triangle);
    if(!plane.vertices_on_one_side(segment)) {
        //check whether the task is reduced to the 2d case
        if(plane.vertices_on_plane(segment)) {
            Triangle_t segment1(triangle.get_a(), 
                                triangle.get_b(), 
                                triangle.get_b());
            Triangle_t segment2(triangle.get_a(), 
                                triangle.get_a(), 
                                triangle.get_c());
            Triangle_t segment3(triangle.get_b(), 
                                triangle.get_c(), 
                                triangle.get_c());
            if(segment_segment_check(segment, segment1)) {
                return true;
            }
            if(segment_segment_check(segment, segment2)) {
                return true;
            }
            if(segment_segment_check(segment, segment3)) {
                return true;
            }
            return false;
        }
        Line_t intersection_planes_line{diff_points(segment)};
        Line_segment_t seg{segment, plane, intersection_planes_line};
        Point_t intersection_point(intersection_planes_line, seg.get_t1());
        return point_triangle_check(intersection_point, triangle);
    }
        
    return false;
}

void compute_interval(Triangle_t& triangle, Vector_t& d, float& min, float& max) {
    float s1 = dot(d, triangle.get_a());
    float s2 = dot(d, triangle.get_b());
    float s3 = dot(d, triangle.get_c());

    min = std::min(std::min(s1, s2), s3);
    max = std::max(std::max(s1, s2), s3);
}

bool triangles2d_check(Triangle_t& triangle1, Triangle_t& triangle2, Plane_t& plane) {
    float min0, max0;
    float min1, max1;
    for(int i = 0; i < 3; ++i) {
        Vector_t v(triangle1[i], triangle1[i + 1]);
        Vector_t d = cross(v, plane.get_v());
        compute_interval(triangle1, d, min0, max0);
        compute_interval(triangle2, d, min1, max1);

        if (max1 < min0 || max0 < min1)
            return false;
    }
    for(int i = 0; i < 3; ++i) {
        Vector_t v(triangle2[i], triangle2[i + 1]);
        Vector_t d = cross(v, plane.get_v());
        compute_interval(triangle1, d, min0, max0);
        compute_interval(triangle2, d, min1, max1);

        if (max1 < min0 || max0 < min1)
            return false;
    }
    return true;
}

bool triangles3d_check(Triangle_t& triangle1, Triangle_t& triangle2, 
                       Plane_t& plane1, Plane_t& plane2) {
    Line_t intersection_planes_line{plane1,plane2};
    Line_segment_t seg1{triangle1, plane2, intersection_planes_line};
    Line_segment_t seg2{triangle2, plane1, intersection_planes_line};
    return seg1.compare_segments(seg2);
}

bool triangle_triangle_check(Triangle_t& triangle1, Triangle_t& triangle2) {
    Plane_t plane1(triangle1);
    Plane_t plane2(triangle2);

    if(!plane1.vertices_on_one_side(triangle2) && !plane2.vertices_on_one_side(triangle1)) {
        if(cross(plane1.get_v(), plane2.get_v()) == 0) {
            if(plane1.planes_match(plane2)) {
                return triangles2d_check(triangle1, triangle2, plane1);
            }
            return false;
        }
        
        return triangles3d_check(triangle1, triangle2, plane1, plane2);
    }
    
    return false;
}

bool check_intersection(Triangle_t& comparison_triangle1, 
                        Triangle_t& comparison_triangle2) {
    comparison_triangle1.check_triangle_type();
    comparison_triangle2.check_triangle_type();

    if(comparison_triangle1.get_type() == IS_POINT &&
       comparison_triangle2.get_type() == IS_POINT) {
        return point_point_check(comparison_triangle1, 
                                 comparison_triangle2);
    }

    if(comparison_triangle1.get_type() == IS_POINT &&
       comparison_triangle2.get_type() == IS_SEGMENT) {
        return segment_point_check(comparison_triangle1.get_a(), 
                                   comparison_triangle2);
    }
    if(comparison_triangle1.get_type() == IS_SEGMENT &&
       comparison_triangle2.get_type() == IS_POINT) {
        return segment_point_check(comparison_triangle2.get_a(), 
                                   comparison_triangle1);
    }

    if(comparison_triangle1.get_type() == IS_POINT &&
       comparison_triangle2.get_type() == IS_TRIANGLE) {
        Point_t point(comparison_triangle1);
        return point_triangle_check(point, comparison_triangle2);
    }
    if(comparison_triangle1.get_type() == IS_TRIANGLE &&
       comparison_triangle2.get_type() == IS_POINT) {
        Point_t point(comparison_triangle2);
        return point_triangle_check(point, comparison_triangle1);
    }

    if(comparison_triangle1.get_type() == IS_SEGMENT &&
       comparison_triangle2.get_type() == IS_SEGMENT) {
        return segment_segment_check(comparison_triangle1, 
                                     comparison_triangle2);
    }

    if(comparison_triangle1.get_type() == IS_SEGMENT &&
       comparison_triangle2.get_type() == IS_TRIANGLE) {
        return segment_triangle_check(comparison_triangle1, 
                                      comparison_triangle2);
    }

    if(comparison_triangle1.get_type() == IS_TRIANGLE &&
       comparison_triangle2.get_type() == IS_SEGMENT) {
        return segment_triangle_check(comparison_triangle2, 
                                      comparison_triangle1);
    }

    if(comparison_triangle1.get_type() == IS_TRIANGLE &&
       comparison_triangle2.get_type() == IS_TRIANGLE) {
        return triangle_triangle_check(comparison_triangle1, 
                                       comparison_triangle2);
    }
}
