#include "transform.h"
#include "point.h" 
/*
Transform class for CS 3505 assignment 2.
This class is used to transform one 2-D point into a different 2-D point.
By: 
**01/23/2025**
*/

// Constructor that has six double-type parameters in this order: 
// a, b, c, d, e, f
Transform::Transform(double a, double b, double c, double d, double e, double f) {
    coefficients[0] = a;
    coefficients[1] = b;
    coefficients[2] = c;
    coefficients[3] = d;
    coefficients[4] = e;
    coefficients[5] = f;
}

// Method to get transformation parameters. Copies the six parameters into the array in the order [a, b, c, d, e, f].
void Transform::getParameters(double params[6]) const {
    for (int i = 0; i < 6; i++) {
        params[i] = coefficients[i];
    }
}

// Overload * operator.
Point Transform::operator*(Point& pt) const {
    double newX = coefficients[0] * pt.getX() + coefficients[1] * pt.getY() + coefficients[2];
    double newY = coefficients[3] * pt.getX() + coefficients[4] * pt.getY() + coefficients[5];
    return Point(newX, newY);
}

// Overload *= operator for Point.
Point& operator*=(Point& pt, const Transform& tr) {
    double newX = tr.coefficients[0] * pt.getX() + tr.coefficients[1] * pt.getY() + tr.coefficients[2];
    double newY = tr.coefficients[3] * pt.getX() + tr.coefficients[4] * pt.getY() + tr.coefficients[5];
    pt = Point(newX, newY);
    return pt;
}

// Overload << operator.
std::ostream& operator<<(std::ostream& output, const Transform& tr) {
    output << "[" 
           << tr.coefficients[0] << ", " << tr.coefficients[1] << ", " << tr.coefficients[2] << ", "
           << tr.coefficients[3] << ", " << tr.coefficients[4] << ", " << tr.coefficients[5] << "]";
    return output;
}