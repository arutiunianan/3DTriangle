#pragma once

#include "../vector/test.h"

TEST(CheckPlane, Subtestv_1) {
    Triangle_t triangle(Point_t(1, -2, 0), Point_t(2, 0, -1), Point_t(0, -1, 2));
    Plane_t plane(triangle);

    Plane_t answer{5, -1, 3, -7};
    ASSERT_TRUE(plane == answer);
}

TEST(CheckPlane, Subtestv_2) {
    Triangle_t triangle(Point_t(1, 2, 3), Point_t(-3, -2, -1), Point_t(0, 0, 0));
    Plane_t plane(triangle);

    Plane_t answer{4, -8, 4, 0};
    ASSERT_TRUE(plane == answer);
}

TEST(CheckPlane, Subtestv_3) {
    Triangle_t triangle(Point_t(1, 2, 3), Point_t(-3, -2, -1), Point_t(0, 0, 0));
    Plane_t plane(triangle);

    Plane_t answer{4, -8, 4, 0};
    ASSERT_TRUE(plane == answer);
}

TEST(CheckPlane, Subtestv_4) {
    Triangle_t triangle(Point_t(1, 0, 0), Point_t(0, 1, 0), Point_t(0, 0, 1));
    Plane_t plane(triangle);

    Plane_t answer{1, 1, 1, -1};
    ASSERT_TRUE(plane == answer);
}

TEST(CheckPlane, Subtestv_5) {
    Triangle_t triangle(Point_t(0, 0, 0), Point_t(1, 1, 1), Point_t(0, 0, 2));
    Plane_t plane(triangle);

    Plane_t answer{2, -2, 0, 0};
    ASSERT_TRUE(plane == answer);
}
