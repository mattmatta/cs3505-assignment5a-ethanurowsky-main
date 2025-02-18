#ifndef TRANSFORM_H
#define TRANSFORM_H

//#include "point.h"
#include <iostream>
#include <array>
class Point; // Forward declaration of Point class

/**
 * Transform class for CS 3505 assignment 2.
 * Represents a 2D affine transformation.
 * By: 
 * 01/23/2025
 */

class Transform {
    private:
        // Array of coefficients.
        double coefficients[6];

    public:
        
        //Constructs a Transform object with coefficients.
        Transform(double a, double b, double c, double d, double e, double f);

        //Method will set the six parameters in the array in the order [a, b, c, d, e, f]
        void getParameters(double parameters[6]) const;

        //Overload the * operator that has a Point parameter and returns a transformed point.
        Point operator*(Point& pt) const;

        //Overload the operator *= for Point.
        friend Point& operator*=(Point& pt, const Transform& tr);

         // Overload the << operator.
        friend std::ostream& operator<<(std::ostream& output, const Transform& tr);
};

#endif

