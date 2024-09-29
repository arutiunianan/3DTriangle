#include "line.h"

struct Line_segment_t: public Line_t {

    Line_segment_t(Point_t a_, Point_t b_): 
                   Line_t(a_, b_) {};

    bool l_segment_intersection(Line_segment_t l_segment);
};