#pragma once

#include "../vector/test.h"

TEST(CheckTriangle, Subtestv_1) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {1, 1, 1}, {0, 0, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_2) {
    Triangle_t triangle1({3, 4, 5}, {5, 6, 7}, {3, 8, 9});
    Triangle_t triangle2({5, 3, 2}, {2, -2, 1}, {2, 2, 0});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_3) {
    Triangle_t triangle1({5, 5, 5}, {2, 2, -3}, {2, 2, 2});
    Triangle_t triangle2({3, 3, 3}, {2, 2, 1}, {4, 2, 1});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_4) {
    Triangle_t triangle1({0, -0.5, 0}, {0, 0.5, 0}, {0, 0, 0.5});
    Triangle_t triangle2({0, 0, 0}, {0, 0, 0}, {0, 0, 0});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_5) {
    Triangle_t triangle1({0, -0.5, 0}, {0, 0.5, 0}, {0, 0, 0.5});
    Triangle_t triangle2({0, 0, 0.25}, {0, 0, 0.25}, {0, 0, 0.25});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_6) {
    Triangle_t triangle1({0, -0.5, 0}, {0, 0.5, 0}, {0, 0, 0.5});
    Triangle_t triangle2({0, 0, 0.6}, {0, 0, 0.6}, {0, 0, 0.6});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_7) {
    Triangle_t triangle1({1, 0, 0}, {-1, 0, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0.5, 1}, {0, -0.5, 0}, {0, -1, -0.5});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_8) {
    Triangle_t triangle1({1, 0, 0}, {-1, 0, 0}, {0, 0, 1});
    Triangle_t triangle2({0, -0.5, 0.5}, {0, 0.5, 0.5}, {0, 1, 0.5});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_9) {
    Triangle_t triangle1({1, 0, 0}, {-1, 0, 0}, {0, 0, 1});
    Triangle_t triangle2({0, -0.5, -0.5}, {0, 0.5, -0.5}, {0, 1, -0.5});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_10) {
    Triangle_t triangle1({1, 0, 0}, {-1, 0, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 1.5, -0.5}, {0, 0.5, -0.5}, {0, 1, -0.5});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_11) {
    Triangle_t triangle1({2, -2, 0}, {2, -2, 0}, {-2, 2, 2});
    Triangle_t triangle2({0.2, -0.4, 0}, {0, 0, 0}, {0, 0, 1});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_12) {
    Triangle_t triangle1({2, -2, 0}, {2, -2, 0}, {-2, 2, 2});
    Triangle_t triangle2({1, -2, -4}, {1, -2, -4}, {0, 0, 1});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_13) {
    Triangle_t triangle1({0.2, -0.4, 0}, {0, 0, 0}, {0, 0, -1});
    Triangle_t triangle2({0, 0, 2}, {0, 0, 2}, {0, 0, -4});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_14) {
    Triangle_t triangle1({0, 1, 0}, {0, -1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {0, 2, 0}, {0, 2, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_15) {
    Triangle_t triangle1({1, 0, 1}, {1, 0, 1}, {0, 2, 0});
    Triangle_t triangle2({-1, 0, 2}, {0, 1, 1}, {0, 1, 1});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_16) {
    Triangle_t triangle1({0, 0, 0}, {0, 2, 0}, {0, 0, 0});
    Triangle_t triangle2({3, 0, 0}, {5, 2, 0}, {6, 0, 0});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_17) {
    Triangle_t triangle1({0.4, -5, 0}, {1, 2, 0}, {5, 0, 0});
    Triangle_t triangle2({-1, 0, 0}, {3, 2, 0}, {6, 2, 0});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_18) {
    Triangle_t triangle1({1, 0, 1}, {1, 0, 5}, {5, 0, 4});
    Triangle_t triangle2({5, 0, 2}, {2.1, 0, 8}, {1, 0, -1});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_19) {
    Triangle_t triangle1({0, 0, 0}, {0, 0, 1}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0.5}, {0, 0, 0.5}, {0, 0, 0.5});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_20) {
    Triangle_t triangle1({0, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0.25, 0.33}, {0, 0.25, 0.33}, {0, 0.25, 0.33});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_21) {
    Triangle_t triangle1({0, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({1, 0.25, 0.33}, {1, 0.25, 0.33}, {1, 0.25, 0.33});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtestv_22) {
    Triangle_t triangle1({0, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {0, 0, 0}, {0, 0, 0});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_23) {
    Triangle_t triangle1({2, -2, -1}, {1, 1, -1}, {2, 2, 1});
    Triangle_t triangle2({2, 0, 0}, {2, 0, 0}, {2, 0, 0});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_24) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {0, 0, 0}, {1, 1, 0});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_25) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {0, 0, 0}, {1, 1, 1});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_26) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {0, 0, 0}, {-1, 1, 1});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_27) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {0, 0, 0}, {0.25, 0.25, 0.25});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_28) {
    Triangle_t triangle1({5, 3, 2}, {1, 1, 0}, {-2, 3, 1});
    Triangle_t triangle2({6, 3, 2}, {1, 3, 0}, {1, 3, 0});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_29) {
    Triangle_t triangle1({5, 3, 2}, {1, 1, 0}, {-2, 3, 1});
    Triangle_t triangle2({6, 2, 7}, {1, 3, 0}, {1, 3, 0});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_30) {
    Triangle_t triangle1({2, 0, 0}, {0, 2, 0}, {0, 0, 0});
    Triangle_t triangle2({0.5, 0.5, 0.5}, {0.5, 0.5, 1}, {0.5, 0.5, 1});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_31) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {1, 1, 1}, {-2, 2, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_32) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {1, 1, 1}, {-2, 2, 20});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_33) {
    Triangle_t triangle1({-1, 5, 4}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {1, 1, 1}, {-2, 2, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}
TEST(CheckTriangle, Subtest_34) {
    Triangle_t triangle1({-1, 5, 4}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({-1, -2, -1}, {-1, -1, -1}, {-2, 2, 2});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_35) {
    Triangle_t triangle1({2, -3, 7}, {1, 4, 6}, {5, 3, -1});
    Triangle_t triangle2({1, 1, 1}, {1, 0, 1}, {1, -1, 3});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_36) {
    Triangle_t triangle1({2, -3, 4}, {1, 4, 6}, {5, 3, -1});
    Triangle_t triangle2({-1, 5, 2}, {2, -1, 4}, {5, 0, 5});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_37) {
    Triangle_t triangle1({2.5, 5.234, -4.234}, {1.31, 5.01, -1.14}, {-1.1, -2.4, 5});
    Triangle_t triangle2({1.5, 2.1, 3.1}, {-1.5, -5.1, 2}, {4.1, 5, 3});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_38) {
    Triangle_t triangle1({2.2, 5.3, -4.2}, {1, 1, -1}, {2, 2, 2});
    Triangle_t triangle2({5, 5, 0}, {1, 1, 1}, {-3, 2, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_39) {
    Triangle_t triangle1({2.2, 5.3, -4.2}, {1, 1, -1}, {2, 2, 2});
    Triangle_t triangle2({5, 5, 0}, {2, 2, 2}, {-3, 2, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_40) {
    Triangle_t triangle1({2.2, 5.3, -4.2}, {1, 1, -1}, {-2, -2, -2});
    Triangle_t triangle2({5, 5, 0}, {1, 1, -1}, {-3, 2, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_41) {
    Triangle_t triangle1({18, 1, 20}, {9, 7, 1}, {3, 19, 6});
    Triangle_t triangle2({3, 4, 9}, {9, 4, 16}, {16, 4, 6});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_42) {
    Triangle_t triangle1({18, 1, 20}, {9, 7, 1}, {3, 19, 6});
    Triangle_t triangle2({5, 16, 16}, {19, 3, 16}, {3, 2, 2});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_43) {
    Triangle_t triangle1({18, 1, 20}, {9, 7, 1}, {3, 19, 6});
    Triangle_t triangle2({2, 17, 18}, {9, 20, 3}, {14, 6, 14});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_44) {
    Triangle_t triangle1({18, 1, 20}, {9, 7, 1}, {3, 19, 6});
    Triangle_t triangle2({12, 7, 6}, {12, 16, 7}, {13, 15, 11});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_45) {
    Triangle_t triangle1({18, 1, 20}, {9, 7, 1}, {3, 19, 6});
    Triangle_t triangle2({12, 4, 10}, {17, 20, 13}, {18, 10, 6});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_46) {
    Triangle_t triangle1({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {5, 5, 0}, {5, 5, 10});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_47) {
    Triangle_t triangle1({0, 0, 0}, {5, 5, 0}, {5, 5, 10});
    Triangle_t triangle2({0.5, 0, 0}, {0, 0, 0}, {0, 0, 0.5});

    ASSERT_TRUE(check_intersection(triangle1, triangle2));
}

TEST(CheckTriangle, Subtest_48) {
    Triangle_t triangle1({2.5, 5, 0}, {5, 10, 0}, {5, 10, 0});
    Triangle_t triangle2({-20, 10, 0}, {20, -4, 0}, {20, -4, 0});

    ASSERT_FALSE(check_intersection(triangle1, triangle2));
}

TEST(triangle, Subtest_49) {
  Triangle_t triangle1({2.123, -2.52, 0}, {5.31, 141, 0}, {5.31, 141, 0});
  Triangle_t triangle2({-20, 10, 0}, {20, -50, 0}, {20, -50, 0});

  ASSERT_FALSE(check_intersection(triangle1, triangle2));
}