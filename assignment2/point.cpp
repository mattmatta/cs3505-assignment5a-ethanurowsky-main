/*
Point class for CS 3505 assignment 2.
A Point holds x and y values.
By Eric Heisler and Ethan Urowsky
01/23/2025
*/
#include "point.h"
#include <iostream>

//Default constructor initializes to (0, 0).
Point::Point(): x(0.0), y(0.0) {}

//This constructor takes initial values for x and y.
Point::Point(double x, double y) : x(x), y(y) {}

//Destructor.
Point::~Point() {}

//Gets x coordinate of point.
double Point::getX() {
    return x;
}

//Gets y coordinate of point.
double Point::getY() {
    return y;
}

// Operators
Point Point::operator*(double scaleFactor) {
	return Point(x*scaleFactor, y*scaleFactor);
}

// This doesn't start with Point:: so it is not in the scope of the class.
// However, it is a friend function, so it can access Point's variables.
std::ostream& operator<<(std::ostream& output, Point pt) {
    output << pt.x << ", " << pt.y;
    return output;
}
