#pragma once

#include "../vector/test.h"

TEST(octree, Subtest_1) {
    size_t N = 8;

    std::list<TriangleWithNum> triangles;

    triangles.push_back({0, {{1, 1, 0}, {3, 1, 0}, {1, 3, 0}}});
    triangles.push_back({1, {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}}});
    triangles.push_back({2, {{1, 0.5, 0}, {1, 0.5, 1}, {0, 0, 0.5}}});
    triangles.push_back({3, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}});
    triangles.push_back({4, {{0, 0, 0}, {0, 3, 3}, {0, 0, 3}}});
    triangles.push_back({5, {{1, 1, 0}, {1, 2, 3}, {5, 4, 8}}});
    triangles.push_back({6, {{9, 9, 9}, {9, 9, 9}, {9, 9, 9}}});
    triangles.push_back({7, {{8, 8, 8}, {8, 8, 8}, {-10, 8, 8}}});

    float minx, miny, minz;
    float maxx, maxy, maxz;
    std::list<TriangleWithNum>::iterator it = triangles.begin();
    for(size_t i = 0; i < N; ++i) {
        minx = std::min(minx, std::min({it->triangle.get_a().get_x(),
                                        it->triangle.get_b().get_x(), 
                                        it->triangle.get_c().get_x()}));
        miny = std::min(miny, std::min({it->triangle.get_a().get_y(),
                                        it->triangle.get_b().get_y(), 
                                        it->triangle.get_c().get_y()}));
        minz = std::min(minz, std::min({it->triangle.get_a().get_z(),
                                        it->triangle.get_b().get_z(), 
                                        it->triangle.get_c().get_z()}));

        maxx = std::max(maxx, std::max({it->triangle.get_a().get_x(),
                                        it->triangle.get_b().get_x(), 
                                        it->triangle.get_c().get_x()}));
        maxy = std::max(maxy, std::max({it->triangle.get_a().get_y(),
                                        it->triangle.get_b().get_y(), 
                                        it->triangle.get_c().get_y()}));
        maxz = std::max(maxz, std::max({it->triangle.get_a().get_z(),
                                        it->triangle.get_b().get_z(), 
                                        it->triangle.get_c().get_z()}));

        ++it;
    }
    BoundingBox initial_box(Point_t{minx, miny, minz}, 
                            Point_t{maxx, maxy, maxz});
    OctTree octree(initial_box, triangles);

    octree.build_tree();

    std::unordered_set<size_t> intersecting_triangles = octree.get_intersection();
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), intersecting_triangles.end());

    std::set<size_t> answer{0, 1, 2, 3, 4, 5};
    ASSERT_TRUE(intersecting_triangles_sorted == answer);
}

TEST(octree, Subtest_2) {
    size_t N = 2;

    std::list<TriangleWithNum> triangles;

    triangles.push_back({0, {{5, 0, 0}, {0, 5, 0}, {0, 0, 5}}});
    triangles.push_back({1, {{1.2, 1.2, 1.2}, {0, 0, 0}, {0, 0, -2}}});

    float minx, miny, minz;
    float maxx, maxy, maxz;
    std::list<TriangleWithNum>::iterator it = triangles.begin();
    for(size_t i = 0; i < N; ++i) {
        minx = std::min(minx, std::min({it->triangle.get_a().get_x(),
                                        it->triangle.get_b().get_x(), 
                                        it->triangle.get_c().get_x()}));
        miny = std::min(miny, std::min({it->triangle.get_a().get_y(),
                                        it->triangle.get_b().get_y(), 
                                        it->triangle.get_c().get_y()}));
        minz = std::min(minz, std::min({it->triangle.get_a().get_z(),
                                        it->triangle.get_b().get_z(), 
                                        it->triangle.get_c().get_z()}));

        maxx = std::max(maxx, std::max({it->triangle.get_a().get_x(),
                                        it->triangle.get_b().get_x(), 
                                        it->triangle.get_c().get_x()}));
        maxy = std::max(maxy, std::max({it->triangle.get_a().get_y(),
                                        it->triangle.get_b().get_y(), 
                                        it->triangle.get_c().get_y()}));
        maxz = std::max(maxz, std::max({it->triangle.get_a().get_z(),
                                        it->triangle.get_b().get_z(), 
                                        it->triangle.get_c().get_z()}));

        ++it;
    }
    BoundingBox initial_box(Point_t{minx, miny, minz}, 
                            Point_t{maxx, maxy, maxz});
    OctTree octree(initial_box, triangles);

    octree.build_tree();

    std::unordered_set<size_t> intersecting_triangles = octree.get_intersection();
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), intersecting_triangles.end());

    std::set<size_t> answer{};
    ASSERT_TRUE(intersecting_triangles_sorted == answer);
}
