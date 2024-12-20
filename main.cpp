#include "octree/octree.h"

#include <fstream>
#include <cmath>
#include <set>
#include <limits>

int main() {
    size_t N;
    std::cin >> N;

    std::list<TriangleWithNum> triangles;

    double minx = std::numeric_limits<double>::max();
    double miny = std::numeric_limits<double>::max();
    double minz = std::numeric_limits<double>::max();
    double maxx = std::numeric_limits<double>::lowest();
    double maxy = std::numeric_limits<double>::lowest();
    double maxz = std::numeric_limits<double>::lowest();

    for(size_t i = 0; i < N; ++i) {
        double x1, y1, z1;
        double x2, y2, z2;
        double x3, y3, z3;
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
