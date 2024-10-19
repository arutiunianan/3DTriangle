#include "plane/plane.h"

int main() {
    /*int N;
    std::cin >> N;

    std::list<Triangle_t> triangles_list;
    for(int i = 0; i < N; i++) {
        float a1, b1, c1,
              a2, b2, c2,
              a3, b3, c3;
        std::cin >> a1 >> b1 >> c1
                 >> a2 >> b2 >> c2
                 >> a3 >> b3 >> c3;
        Point_t point1(a1, b1, c1);
        Point_t point2(a2, b2, c2);
        Point_t point3(a3, b3, c3);
        Triangle_t triangle(point1, point2, point3);

        triangles_list.push_back(triangle);
    }

    std::vector<bool> has_intersection(N, false);
    for(int i = 0; i < N - 1; i++) {
        int j = 1;
        std::list<Triangle_t>::iterator comparison_triangle1 = triangles_list.begin();
        std::list<Triangle_t>::iterator comparison_triangle2 = std::next(comparison_triangle1, j);
        while(comparison_triangle2 != triangles_list.end()) {
            has_intersection[i] = has_intersection[i] || check_intersection(*comparison_triangle1, *comparison_triangle2);
            has_intersection[i + j] = has_intersection[i] || has_intersection[i + j];

            comparison_triangle2++;
            j++;
        }

        triangles_list.pop_front();
    }*/


   

   //Vector_t v1(1, 0, 3);
   //Vector_t v2(2 ,3, 4);
   //float new_v = dot(v1, v2);
   //std::cout << new_v << "\n";


    /*Point_t point11(0, 0, 0);
    Point_t point12(1, 0, 0);
    Point_t point13(0, 1, 0);

    Point_t point21(0, 0, 0);
    Point_t point22(1, 0, 0);
    Point_t point23(1, 1, 0);

    Triangle_t comparison_triangle1(point11,point12,point13); 
    Triangle_t comparison_triangle2(point21,point22,point23); 
    std::cout << check_intersection(comparison_triangle1,comparison_triangle2);*/

    /*Line_t intersection_planes_line{};
    std::cout << intersection_planes_line.vector.z << " " << intersection_planes_line.point.z << "\n";*/

    Triangle_t triangle1({0, -0.5, 0}, {0, 0.5, 0}, {0, 0, 0.5});
    Triangle_t triangle2({-0.5, 0, 0}, {0.5, 0, 0}, {0, 0, 0});

    /*Triangle_t triangle1 {Point_t(0, -0.5, 0), Point_t(0, 0.5, 0), Point_t(0, 0, 0.5)};
    Triangle_t triangle2 {Point_t(0.25, 0, 0.25), Point_t(-0.25, 0, 0.25), Point_t(0, 0, 1)};*/
    std::cout << check_intersection(triangle1, triangle2) << "\n";
}