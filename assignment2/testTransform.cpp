#include <iostream>
#include "point.h"
#include "transform.h"

/*
Transform test class for CS 3505 assignment 2.
This class is used as a test program.
By: Ethan Urowsky
**01/23/2025**
*/

int main() {
    // construct a Point and a Transform object.
    Point pt(1.0, 0.0);
    Transform tr(1.005, -0.1, 0.02, 0.1, 1.005, -0.02);

    // 200 iterations
    for (int i = 0; i < 200; ++i) {
        pt *= tr; // Apply transformation
        std::cout << pt << std::endl; // Print the Point
    }

    return 0;
}