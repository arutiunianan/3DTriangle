#pragma once

#include "../plane/plane.h"

class Line_segment_t final {
private:
    double t1;
    double t2;

public:
    Line_segment_t(Triangle_t& triangle, Plane_t& plane, Line_t& line);
    
    double get_t1() const;
    double get_t2() const;

    double compare_segments(Line_segment_t line_segment) const;

private:
    double intersection_point(Point_t vertex1, Point_t vertex2, 
                              double dist1, double dist2, Line_t& line) const;
};
