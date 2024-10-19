#ifndef VTEST_H_
#define VTEST_H_

#include <gtest/gtest.h>
#include "../../line/line_segment.h"

TEST(CheckVector, Subtestv_1) {
    Vector_t v1(1, 0, 3);
    Vector_t v2(2 ,3, 4);

    float new_v1 = dot(v1, v2);
    Vector_t new_v2 = cross(v1, v2);

    ASSERT_TRUE(new_v2.x == -9);
    ASSERT_TRUE(new_v2.y == 2);
    ASSERT_TRUE(new_v2.z == 3);
    ASSERT_TRUE(new_v1 == 14);
}

TEST(CheckVector, Subtestv_2) {
    Vector_t v1(2, -3, 0);
    Vector_t v2(4 ,0, 13);
    
    float new_v1 = dot(v1, v2);
    Vector_t new_v2 = cross(v1, v2);

    ASSERT_TRUE(new_v2.x == -39);
    ASSERT_TRUE(new_v2.y == -26);
    ASSERT_TRUE(new_v2.z == 12);
    ASSERT_TRUE(new_v1 == 8);
}

#endif // #define VTEST_H_