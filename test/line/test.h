#ifndef LTEST_H_
#define LTEST_H_

#include "../vector/test.h"

TEST(CheckLine, Subtestv_1) {
    Plane_t plane1({1, 1, 1}, -1);
    Plane_t plane2({2, -2, 0}, 0);
    Line_t line(plane1, plane2);

    ASSERT_NEAR(line.vector.x, -2, 0.1f);
    ASSERT_NEAR(line.vector.y, -2, 0.0001f);
    ASSERT_NEAR(line.vector.z, 4, 0.0001f);

    ASSERT_NEAR(line.point.x, 0.3333, 0.0001f);
    ASSERT_NEAR(line.point.x, 0.3333, 0.0001f);
    ASSERT_NEAR(line.point.x, 0.3333, 0.0001f);
}

TEST(CheckLine, Subtestv_2) {
    Triangle_t triangle({0, -0.5, 0}, {0, 0.5, 0}, {0, 0, 0.5});
    Plane_t plane({0, 0.35, 0}, 0);
    Line_t line({0, 0, -0.1875}, {0, 0, 0});
    Line_segment_t seg(triangle, plane, line);

    ASSERT_NEAR(seg.t1, -2.6667, 0.0001f);
    ASSERT_NEAR(seg.t2, 0, 0.0001f);
}

TEST(CheckLine, Subtestv_3) {
    Triangle_t triangle({0.25, 0, 0.25}, {-0.25, 0, 0.25}, {0, 0, 1});
    Plane_t plane({0.5, 0, 0}, 0);
    Line_t line({0, 0, -0.1875}, {0, 0, 0});
    Line_segment_t seg(triangle, plane, line);

    ASSERT_NEAR(seg.t1, -5.3333, 0.0001f);
    ASSERT_NEAR(seg.t2, -1.3333, 0.0001f);
}

TEST(CheckLine, Subtestv_4) {
    Triangle_t triangle({1, 0, 0}, {0, 1, 0}, {0, 0, 1});
    Plane_t plane({2, -2, 0}, 0);
    Line_t line({-2, -2, 4}, {0.3333, 0.3333, 0.3333});
    Line_segment_t seg(triangle, plane, line);

    ASSERT_NEAR(seg.t1, -0.0833, 0.0001f);
    ASSERT_NEAR(seg.t2, 0.1666, 0.0001f);
}

TEST(CheckLine, Subtestv_5) {
    Triangle_t triangle({0, 0, 0}, {1, 1, 1}, {0, 0, 2});
    Plane_t plane({1, 1, 1}, -1);
    Line_t line({-2, -2, 4}, {0.3333, 0.3333, 0.3333});
    Line_segment_t seg(triangle, plane, line);

    ASSERT_NEAR(seg.t1, 0, 0.0001f);
    ASSERT_NEAR(seg.t2, 0.1666, 0.0001f);
}
#endif // #define LTEST_H_