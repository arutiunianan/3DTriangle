#ifndef TTEST_H_
#define TTEST_H_

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

#endif // #define TTEST_H_