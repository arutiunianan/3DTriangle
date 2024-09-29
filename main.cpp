#include "line/line.h"

int main() {
    int N;
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
    }
}