#include "../line/line.h"

bool check_intersection(Triangle_t comparison_triangle1, 
                        Triangle_t comparison_triangle2) {
    Plane_t plane1(comparison_triangle1);
    Plane_t plane2(comparison_triangle2);

    Line_t line(plane1, plane2);
    if(line.vector == 0) {
        return false;
    }
}