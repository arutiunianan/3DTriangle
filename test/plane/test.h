#ifndef PTEST_H_
#define PTEST_H_

#include "../vector/test.h"

TEST(CheckPlane, Subtestv_1) {
    Triangle_t triangle(Point_t(1, -2, 0), Point_t(2, 0, -1), Point_t(0, -1, 2));
    Plane_t plane(triangle);

    ASSERT_TRUE(plane.vector.x == 5);
    ASSERT_TRUE(plane.vector.y == -1);
    ASSERT_TRUE(plane.vector.z == 3);
    ASSERT_TRUE(plane.distance == -7);
}

TEST(CheckPlane, Subtestv_2) {
    Triangle_t triangle(Point_t(1, 2, 3), Point_t(-3, -2, -1), Point_t(0, 0, 0));
    Plane_t plane(triangle);

    ASSERT_TRUE(plane.vector.x == 4);
    ASSERT_TRUE(plane.vector.y == -8);
    ASSERT_TRUE(plane.vector.z == 4);
    ASSERT_TRUE(plane.distance == 0);
}

TEST(CheckPlane, Subtestv_3) {
    Triangle_t triangle(Point_t(1, 2, 3), Point_t(-3, -2, -1), Point_t(0, 0, 0));
    Plane_t plane(triangle);

    ASSERT_TRUE(plane.vector.x == 4);
    ASSERT_TRUE(plane.vector.y == -8);
    ASSERT_TRUE(plane.vector.z == 4);
    ASSERT_TRUE(plane.distance == 0);
}

TEST(CheckPlane, Subtestv_4) {
    Triangle_t triangle(Point_t(1, 0, 0), Point_t(0, 1, 0), Point_t(0, 0, 1));
    Plane_t plane(triangle);

    ASSERT_TRUE(plane.vector.x == 1);
    ASSERT_TRUE(plane.vector.y == 1);
    ASSERT_TRUE(plane.vector.z == 1);
    ASSERT_TRUE(plane.distance == -1);
}

TEST(CheckPlane, Subtestv_5) {
    Triangle_t triangle(Point_t(0, 0, 0), Point_t(1, 1, 1), Point_t(0, 0, 2));
    Plane_t plane(triangle);

    ASSERT_TRUE(plane.vector.x == 2);
    ASSERT_TRUE(plane.vector.y == -2);
    ASSERT_TRUE(plane.vector.z == 0);
    ASSERT_TRUE(plane.distance == 0);
}
#endif // #define VTEST_H_