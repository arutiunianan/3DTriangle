#include "plane/plane.h"

int main() {
    Triangle_t triangle1({0, 1, 0}, {0, -1, 0}, {0, 0, 1});
    Triangle_t triangle2({0, 0, 0}, {0, 2, 0}, {0, 2, 2});

    std::cout << check_intersection(triangle1, triangle2) << "\n";
}