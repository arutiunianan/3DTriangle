#pragma once

#include "../vector/test.h"
#include <fstream>

bool run_test_from_file(size_t file_num) {
    std::string file_path = std::string(CMAKE_CURRENT_SOURCE_DIR) + "/test/test_files/file" + 
                            std::to_string(file_num) + ".txt";
    std::ifstream test_file;
    test_file.open(file_path);
    assert(test_file);

    size_t N;
    test_file >> N;

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
        test_file >> x1 >> y1 >> z1;
        test_file >> x2 >> y2 >> z2;
        test_file >> x3 >> y3 >> z3;

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
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), 
                                                   intersecting_triangles.end());

    std::string ans_file_path = std::string(CMAKE_CURRENT_SOURCE_DIR) + "/test/test_files/file" + 
                                std::to_string(file_num) + "ans.txt";
    std::ifstream test_ans_file;
    test_ans_file.open(ans_file_path);
    assert(test_ans_file);

    std::set<size_t> answer;
    size_t number;
    while(test_ans_file >> number) {
        answer.insert(number);
    }

    test_file.close();
    test_ans_file.close();

    return intersecting_triangles_sorted == answer;
}

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

    double minx, miny, minz;
    double maxx, maxy, maxz;
    std::list<TriangleWithNum>::iterator it = triangles.begin();
    for(size_t i = 0; i < N; ++i) {
        minx = std::min(minx, std::min(it->triangle.get_a().get_x(),
                              std::min(it->triangle.get_b().get_x(), 
                                       it->triangle.get_c().get_x())));
        miny = std::min(miny, std::min(it->triangle.get_a().get_y(),
                              std::min(it->triangle.get_b().get_y(), 
                                       it->triangle.get_c().get_y())));
        minz = std::min(minz, std::min(it->triangle.get_a().get_z(),
                              std::min(it->triangle.get_b().get_z(), 
                                       it->triangle.get_c().get_z())));

        maxx = std::max(maxx, std::max(it->triangle.get_a().get_x(),
                              std::max(it->triangle.get_b().get_x(), 
                                       it->triangle.get_c().get_x())));
        maxy = std::max(maxy, std::max(it->triangle.get_a().get_y(),
                              std::max(it->triangle.get_b().get_y(), 
                                       it->triangle.get_c().get_y())));
        maxz = std::max(maxz, std::max(it->triangle.get_a().get_z(),
                              std::max(it->triangle.get_b().get_z(), 
                                       it->triangle.get_c().get_z())));

        ++it;
    }
    BoundingBox initial_box(Point_t{minx, miny, minz}, 
                            Point_t{maxx, maxy, maxz});
    OctTree octree(initial_box, triangles);

    octree.build_tree();

    std::unordered_set<size_t> intersecting_triangles = octree.get_intersection();
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), 
                                                   intersecting_triangles.end());

    std::set<size_t> answer{0, 1, 2, 3, 4, 5};
    ASSERT_TRUE(intersecting_triangles_sorted == answer);
}

TEST(octree, Subtest_2) {
    size_t N = 2;

    std::list<TriangleWithNum> triangles;

    triangles.push_back({0, {{5, 0, 0}, {0, 5, 0}, {0, 0, 5}}});
    triangles.push_back({1, {{1.2, 1.2, 1.2}, {0, 0, 0}, {0, 0, -2}}});

    double minx, miny, minz;
    double maxx, maxy, maxz;
    std::list<TriangleWithNum>::iterator it = triangles.begin();
    for(size_t i = 0; i < N; ++i) {
        minx = std::min(minx, std::min(it->triangle.get_a().get_x(),
                              std::min(it->triangle.get_b().get_x(), 
                                       it->triangle.get_c().get_x())));
        miny = std::min(miny, std::min(it->triangle.get_a().get_y(),
                              std::min(it->triangle.get_b().get_y(), 
                                       it->triangle.get_c().get_y())));
        minz = std::min(minz, std::min(it->triangle.get_a().get_z(),
                              std::min(it->triangle.get_b().get_z(), 
                                       it->triangle.get_c().get_z())));

        maxx = std::max(maxx, std::max(it->triangle.get_a().get_x(),
                              std::max(it->triangle.get_b().get_x(), 
                                       it->triangle.get_c().get_x())));
        maxy = std::max(maxy, std::max(it->triangle.get_a().get_y(),
                              std::max(it->triangle.get_b().get_y(), 
                                       it->triangle.get_c().get_y())));
        maxz = std::max(maxz, std::max(it->triangle.get_a().get_z(),
                              std::max(it->triangle.get_b().get_z(), 
                                       it->triangle.get_c().get_z())));

        ++it;
    }
    BoundingBox initial_box(Point_t{minx, miny, minz}, 
                            Point_t{maxx, maxy, maxz});
    OctTree octree(initial_box, triangles);

    octree.build_tree();

    std::unordered_set<size_t> intersecting_triangles = octree.get_intersection();
    std::set<size_t> intersecting_triangles_sorted(intersecting_triangles.begin(), 
                                                   intersecting_triangles.end());

    std::set<size_t> answer{};
    ASSERT_TRUE(intersecting_triangles_sorted == answer);
}

TEST(octree, Subtest_3) {
    ASSERT_TRUE(run_test_from_file(1));
}

TEST(octree, Subtest_4) {
    ASSERT_TRUE(run_test_from_file(2));
}

TEST(octree, Subtest_5) {
    ASSERT_TRUE(run_test_from_file(3));
}

TEST(octree, Subtest_6) {
    ASSERT_TRUE(run_test_from_file(4));
}

TEST(octree, Subtest_7) {
    ASSERT_TRUE(run_test_from_file(5));
}
