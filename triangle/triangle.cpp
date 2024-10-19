#include "../line/line_segment.h"
#include <float.h>

bool check_intersection(Triangle_t comparison_triangle1, 
                        Triangle_t comparison_triangle2) {
    //the planes in which our triangles are located
    Plane_t plane1(comparison_triangle1);
    Plane_t plane2(comparison_triangle2);

    //std::cout << plane1.vector.x << " " << plane1.vector.y << " " << plane1.vector.z << " " << plane1.distance << "\n";
    //std::cout << plane2.vector.x << " " << plane2.vector.y << " " << plane2.vector.z << " " << plane2.distance << "\n";

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