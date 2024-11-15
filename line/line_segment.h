#pragma once

#include "../plane/plane.h"

class Line_segment_t final {
private:
    float t1;
    float t2;

public:
    Line_segment_t(Triangle_t& triangle, Plane_t& plane, Line_t& line);
    
    float get_t1() const;
    float get_t2() const;

    float compare_segments(Line_segment_t line_segment) const;

private:
    float intersection_point(Point_t vertex1, Point_t vertex2, 
                             float dist1, float dist2, Line_t& line) const;
};
