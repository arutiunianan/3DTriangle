#include "vector/test.h"
#include "plane/test.h"
#include "line/test.h"
#include "triangle/test.h"
#include "octree/test.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}