#include "line_segment.h"

Line_t::Line_t(Plane_t& p1, Plane_t& p2) {
    Vector_t d = cross(p1.vector, p2.vector);
    vector = -d;
    float s1 = -p1.distance;
    float s2 = -p2.distance;
    float n1n2dot = dot(p1.vector, p2.vector);
    float n1normsqr = dot(p1.vector, p1.vector);
    float n2normsqr = dot(p2.vector, p2.vector);
    float a = ((s2 * n1n2dot - s1 * n2normsqr)) / ((n1n2dot * n1n2dot - n1normsqr * n2normsqr));
    float b = ((s1 * n1n2dot - s2 * n2normsqr)) / ((n1n2dot * n1n2dot - n1normsqr * n2normsqr));
    point = p1.vector * a + p2.vector * b;
}

float Line_t::get_t(Point_t p) {
    return (p.x - point.x) / vector.x;
}

bool Line_t::lines_match(Line_t& line) {
    float k = vector.x / line.vector.x;
    if((point.x / line.point.x) == k &&
       (point.y / line.point.y) == k &&
       (point.z / line.point.z) == k) {
        return true;
    }
    return false;
}

float intersection_point(Point_t& vertex1, Point_t& vertex2, float dist1, float dist2, Line_t& line) {
    Vector_t PV1(line.point, vertex1);
    Vector_t PV2(line.point, vertex2);
    float t1 = dot(line.vector, PV1) / dot(line.vector, line.vector);
    float t2 = dot(line.vector, PV2) / dot(line.vector, line.vector);

    return (t1 + (t2 - t1) * (dist1 / (dist1 - dist2)));
}

Line_segment_t::Line_segment_t(Triangle_t& triangle, Plane_t& plane, Line_t& inst_line) {
    float f1 = plane.put_point_in_equation(triangle.a);
    float f2 = plane.put_point_in_equation(triangle.b);
    float f3 = plane.put_point_in_equation(triangle.c);

    if(f1 * f2 >= 0) {
        t1 = intersection_point(triangle.a, triangle.c, f1, f3, inst_line);
        t2 = intersection_point(triangle.b, triangle.c, f2, f3, inst_line);
    }
    if(f1 * f3 >= 0) {
        t1 = intersection_point(triangle.a, triangle.b, f1, f2, inst_line);
        t2 = intersection_point(triangle.c, triangle.b, f3, f2, inst_line);
    }
    if(f2 * f3 >= 0) {
        t1 = intersection_point(triangle.b, triangle.a, f2, f1, inst_line);
        t2 = intersection_point(triangle.c, triangle.a, f3, f1, inst_line);
    }

    if(t1 > t2) {
        float tmp = t1;
        t1 = t2;
        t2 = tmp;
    }
}

float Line_segment_t::compare_segments(Line_segment_t line_segment) {
    if(t1 > line_segment.t2) {
        return true;
    }
    if(t2 < line_segment.t1) {
        return false;
    }
    return true;
}