#pragma once

#include "../vector/test.h"
#include <fstream>

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

TEST(octree, Subtest_3) {
    std::string file_path  = std::string(CMAKE_CURRENT_SOURCE_DIR) + "/test/test_files/file1.txt";
    std::ifstream test_file;
    test_file.open(file_path);
    assert(test_file);

    size_t N;
    test_file >> N;

    std::list<TriangleWithNum> triangles;

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
        test_file >> x1 >> y1 >> z1;
        test_file >> x2 >> y2 >> z2;
        test_file >> x3 >> y3 >> z3;


        minx = std::min(minx, std::min({x1, x2, x3}));
        miny = std::min(miny, std::min({y1, y2, y3}));
        minz = std::min(minz, std::min({z1, z2, z3}));

        maxx = std::max(maxx, std::max({x1, x2, x3}));
        maxy = std::max(maxy, std::max({y1, y2, y3}));
        maxz = std::max(maxz, std::max({z1, z2, z3}));

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

    std::string ans_file_path = std::string(CMAKE_CURRENT_SOURCE_DIR) + "/test/test_files/file1ans.txt";
    std::ifstream test_ans_file;
    test_ans_file.open(ans_file_path);
    assert(test_ans_file);

    std::set<size_t> answer;
    size_t number;
    while (test_ans_file >> number) {
        answer.insert(number);
    }

    ASSERT_TRUE(intersecting_triangles_sorted == answer);

    test_file.close();
    test_ans_file.close();
}