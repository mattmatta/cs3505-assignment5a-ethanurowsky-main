#ifndef POINT_H
#define POINT_H
/*
Point class for CS 3505 assignment 2.
A Point holds x and y values.
By Eric Heisler and Ethan Urowsky
01/23/2025
*/
#include <iostream> 

// Forward declaration of Transform class
class Transform;

class Point {
private:
    //x and y coordinate of the point.
    double x,y;  
public:
    // default constructor initializes to (0, 0)
    Point();
    // This constructor takes initial values for x and y
    Point(double initX, double initY);
    // The destructor does nothing because we didn't allocate any new memory
    ~Point();
    // Getter for the x value
    double getX();
    // Getter for the y value
    double getY();
    // Operators
    Point operator*(double scaleFactor);
    // Friend insertion operator to make printing easy
    friend std::ostream& operator<<(std::ostream& output, Point pt);
     // Friend operator for *=
    friend Point& operator*=(Point& pt, const Transform& tr);
};

#endif // include guard for POINT_H