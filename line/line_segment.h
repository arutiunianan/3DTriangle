#pragma once
#include "../plane/plane.h"

struct Line_segment_t {
    float t1;
    float t2;

    Line_segment_t(Triangle_t& triangle, Plane_t& plane, Line_t& line);
    float compare_segments(Line_segment_t line_segment);
    //bool l_segment_intersection(Line_segment_t l_segment);
};