#include "octree/octree.h"

#include <fstream>
#include <cmath>
#include <set>

int main() {
    size_t N;
    std::cin >> N;

    std::list<TriangleWithNum> triangles;

    float minx, miny, minz;
    float maxx, maxy, maxz;
    for(size_t i = 0; i < N; ++i) {
        float x1, y1, z1;
        float x2, y2, z2;
        float x3, y3, z3;
        std::cin >> x1 >> y1 >> z1;
        std::cin >> x2 >> y2 >> z2;
        std::cin >> x3 >> y3 >> z3;


        minx = std::min(minx, std::min({x1, x2, x3}));
        miny = std::min(minx, std::min({y1, y2, y3}));
        minz = std::min(minx, std::min({z1, z2, z3}));

        maxx = std::max(minx, std::max({x1, x2, x3}));
        maxy = std::max(minx, std::max({y1, y2, y3}));
        maxz = std::max(minx, std::max({z1, z2, z3}));

        Triangle_t triangle{{x1, y1, z1}, 
                            {x2, y2, z2}, 
                            {x3, y3, z3}};
        triangles.push_back({i, triangle});
    }

    BoundingBox initial_box(Point_t{minx, miny, minz}, 
                            Point_t{maxx, maxy, maxz});
    OctTree octree(initial_box, triangles);

    octree.build_tree();

    std::unordered_set<size_t> intersecting_triangles = octree.get_intersection();
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), intersecting_triangles.end());

    for(const auto& num : intersecting_triangles_sorted)
    {
        std::cout << num << std::endl;
    }
}
