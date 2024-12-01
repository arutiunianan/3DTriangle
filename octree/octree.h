#pragma once

#include "../triangle/triangle.h"

#include <unordered_set>
#include <list>
#include <queue>

class TriangleWithNum {
public:
    size_t num;
    Triangle_t triangle;

    TriangleWithNum(size_t n, Triangle_t t):
                    num(n), triangle(t) {};
};

class BoundingBox final {
public:
    Point_t min;
    Point_t max;

    BoundingBox() {}
    BoundingBox(Point_t min, Point_t max): 
        min(min), max(max) {}

    bool contains_triangle(Triangle_t triangle);
    bool contains_point(Point_t point);
};

class OctTree final {
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

    void print_tree(int depth = 0) const;

    std::unordered_set<size_t> get_intersection(std::list<TriangleWithNum>& parent_triangles);
    std::unordered_set<size_t> get_intersection();
};