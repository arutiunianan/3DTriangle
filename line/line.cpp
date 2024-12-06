#include "line_segment.h"

#include <cmath>

const double DOUBLE_TOLERANCE = 1e-9;

Line_t::Line_t(Plane_t& p1, Plane_t& p2) {
    Vector_t d = cross(p1.get_v(), p2.get_v());
    vector = -d;
    double s1 = -p1.get_d();
    double s2 = -p2.get_d();
    double n1n2dot = dot(p1.get_v(), p2.get_v());
    double n1normsqr = dot(p1.get_v(), p1.get_v());
    double n2normsqr = dot(p2.get_v(), p2.get_v());
    double a = ((s2 * n1n2dot - s1 * n2normsqr)) / 
              ((n1n2dot * n1n2dot - n1normsqr * n2normsqr));
    double b = ((s1 * n1n2dot - s2 * n2normsqr)) / 
              ((n1n2dot * n1n2dot - n1normsqr * n2normsqr));
    point = p1.get_v() * a + p2.get_v() * b;
}

Vector_t Line_t::get_v() const {
    return vector;
}
Point_t  Line_t::get_p() const {
    return point;
}

double Line_t::get_t(Point_t p, int i) const {
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

double Line_segment_t::intersection_point(Point_t vertex1, Point_t vertex2, 
                         double dist1, double dist2, Line_t& line) const {
    Vector_t PV1(line.get_p(), vertex1);
    Vector_t PV2(line.get_p(), vertex2);
    double t1 = dot(line.get_v(), PV1) / dot(line.get_v(), line.get_v());
    double t2 = dot(line.get_v(), PV2) / dot(line.get_v(), line.get_v());

    return (t1 + (t2 - t1) * (dist1 / (dist1 - dist2)));
}

Line_segment_t::Line_segment_t(Triangle_t& triangle, Plane_t& plane, Line_t& inst_line) {
    double f1 = plane.put_point_in_equation(triangle.get_a());
    if(std::abs(f1) < DOUBLE_TOLERANCE) {
        f1 = 0;
    }
    double f2 = plane.put_point_in_equation(triangle.get_b());
    if(std::abs(f2) < DOUBLE_TOLERANCE) {
        f2 = 0;
    }
    double f3 = plane.put_point_in_equation(triangle.get_c());
    if(std::abs(f3) < DOUBLE_TOLERANCE) {
        f3 = 0;
    }

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
        double tmp = t1;
        t1 = t2;
        t2 = tmp;
    }
}

double Line_segment_t::get_t1() const {
    return t1;
}
double Line_segment_t::get_t2() const {
    return t2;
}

double Line_segment_t::compare_segments(Line_segment_t line_segment) const {
    if(t1 > line_segment.t2) {
        return false;
    }
    if(t2 < line_segment.t1) {
        return false;
    }

    if(std::isinf(t1)) {
        if(t2 > line_segment.t1 || t2 < line_segment.t2) {
            return false;
        }
    }
    if(std::isinf(t2)) {
        if(t1 > line_segment.t1 || t1 < line_segment.t2) {
            return false;
        }
    }
    if(std::isinf(line_segment.t1)) {
        if(line_segment.t2 > t1 || line_segment.t2 < t2) {
            return false;
        }
    }
    if(std::isinf(line_segment.t2)) {
        if(line_segment.t1 > t1 || line_segment.t1 < t2) {
            return false;
        }
    }

    return true;
}