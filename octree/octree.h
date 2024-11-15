#pragma once

#include "../triangle/triangle.h"

#include <unordered_set>
#include <list>
#include <queue>

struct TriangleWithNum {
    size_t num;
    Triangle_t triangle;
};

class BoundingBox final {
public:
    Point_t min;
    Point_t max;

    BoundingBox() {}
    BoundingBox(Point_t min, Point_t max): 
        min(min), max(max) {}

    bool contains_triangle(const Triangle_t& triangle);

    bool contains_point(const Point_t& point) const;
};

class OctTree final
{
    std::list<TriangleWithNum> local_triangles;
    BoundingBox boundary;

    OctTree* children_nodes[8] = {nullptr};

    const double MIN_OCTANT_SIZE = 1;
public:
    OctTree() {};
    OctTree(const BoundingBox& bounding_box, const std::list<TriangleWithNum>& local_triangles):
            boundary(bounding_box), local_triangles(local_triangles) {};
    ~OctTree();

    void build_tree();

    std::unordered_set<size_t> get_intersection(std::list<TriangleWithNum>& parent_triangles);
    std::unordered_set<size_t> get_intersection();
};