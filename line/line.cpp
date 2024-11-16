#include "line_segment.h"

Line_t::Line_t(Plane_t& p1, Plane_t& p2) {
    Vector_t d = cross(p1.get_v(), p2.get_v());
    vector = -d;
    float s1 = -p1.get_d();
    float s2 = -p2.get_d();
    float n1n2dot = dot(p1.get_v(), p2.get_v());
    float n1normsqr = dot(p1.get_v(), p1.get_v());
    float n2normsqr = dot(p2.get_v(), p2.get_v());
    float a = ((s2 * n1n2dot - s1 * n2normsqr)) / 
              ((n1n2dot * n1n2dot - n1normsqr * n2normsqr));
    float b = ((s1 * n1n2dot - s2 * n2normsqr)) / 
              ((n1n2dot * n1n2dot - n1normsqr * n2normsqr));
    point = p1.get_v() * a + p2.get_v() * b;
}

Vector_t Line_t::get_v() const {
    return vector;
}
Point_t  Line_t::get_p() const {
    return point;
}

float Line_t::get_t(Point_t p, int i) const {
    return (p[i] - point[i]) / vector[i];
}

bool Line_t::lines_match(Line_t& line) const {
    Vector_t v{point, line.get_p()};
    return cross(v, vector) == 0;
}

void Line_t::print() const {
    vector.print(); 
    point.print();
}

float Line_segment_t::intersection_point(Point_t vertex1, Point_t vertex2, 
                         float dist1, float dist2, Line_t& line) const {
    Vector_t PV1(line.get_p(), vertex1);
    Vector_t PV2(line.get_p(), vertex2);
    float t1 = dot(line.get_v(), PV1) / dot(line.get_v(), line.get_v());
    float t2 = dot(line.get_v(), PV2) / dot(line.get_v(), line.get_v());

    return (t1 + (t2 - t1) * (dist1 / (dist1 - dist2)));
}

Line_segment_t::Line_segment_t(Triangle_t& triangle, Plane_t& plane, Line_t& inst_line) {
    float f1 = plane.put_point_in_equation(triangle.get_a());
    float f2 = plane.put_point_in_equation(triangle.get_b());
    float f3 = plane.put_point_in_equation(triangle.get_c());

    if(f1 * f2 >= 0) {
        t1 = intersection_point(triangle.get_a(), triangle.get_c(), 
                                f1, f3, inst_line);
        t2 = intersection_point(triangle.get_b(), triangle.get_c(),
                                f2, f3, inst_line);
    }
    if(f1 * f3 >= 0) {
        t1 = intersection_point(triangle.get_a(), triangle.get_b(), 
                                f1, f2, inst_line);
        t2 = intersection_point(triangle.get_c(), triangle.get_b(), 
                                f3, f2, inst_line);
    }
    if(f2 * f3 >= 0) {
        t1 = intersection_point(triangle.get_b(), triangle.get_a(), 
                                f2, f1, inst_line);
        t2 = intersection_point(triangle.get_c(), triangle.get_a(), 
                                f3, f1, inst_line);
    }

    if(t1 > t2) {
        float tmp = t1;
        t1 = t2;
        t2 = tmp;
    }
}

float Line_segment_t::get_t1() const {
    return t1;
}
float Line_segment_t::get_t2() const {
    return t2;
}

float Line_segment_t::compare_segments(Line_segment_t line_segment) const {
    if(t1 > line_segment.t2) {
        return false;
    }
    if(t2 < line_segment.t1) {
        return false;
    }
    return true;
}