#include "../octree/octree.h"

#include <fstream>
#include <cmath>
#include <set>
#include <limits>

int main() {
    size_t N;
    std::cin >> N;

    std::vector<Triangle_t> triangles;

    float minx = std::numeric_limits<float>::max();
    float miny = std::numeric_limits<float>::max();
    float minz = std::numeric_limits<float>::max();
    float maxx = std::numeric_limits<float>::lowest();
    float maxy = std::numeric_limits<float>::lowest();
    float maxz = std::numeric_limits<float>::lowest();

    for(size_t i = 0; i < N; ++i) {
        float x1, y1, z1;
        float x2, y2, z2;
        float x3, y3, z3;
        std::cin >> x1 >> y1 >> z1;
        std::cin >> x2 >> y2 >> z2;
        std::cin >> x3 >> y3 >> z3;

        minx = std::min(minx, std::min(x1, std::min(x2, x3)));
        miny = std::min(miny, std::min(y1, std::min(y2, y3)));
        minz = std::min(minz, std::min(z1, std::min(z2, z3)));

        maxx = std::max(maxx, std::max(x1, std::max(x2, x3)));
        maxy = std::max(maxy, std::max(y1, std::max(y2, y3)));
        maxz = std::max(maxz, std::max(z1, std::max(z2, z3)));

        Triangle_t triangle{{x1, y1, z1}, 
                            {x2, y2, z2}, 
                            {x3, y3, z3}};
        triangles.push_back(triangle);
    }
    std::unordered_set<size_t> intersecting_triangles;
    for(size_t i = 0; i < N; ++i) {
        for(size_t j = i + 1; j < N; ++j) {
            if(check_intersection(triangles[i], triangles[j])) {
                intersecting_triangles.insert(i);
                intersecting_triangles.insert(j);
            }
        }
    }
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), intersecting_triangles.end());

    for(const auto& num : intersecting_triangles_sorted)
    {
        std::cout << num << std::endl;
    }
}
