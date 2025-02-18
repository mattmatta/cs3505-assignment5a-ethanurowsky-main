#include "pngWriter.h"
#include "transform.h"  
#include "point.h"      
#include <iostream>
#include <cstdlib>

/*
fernPNG file for CS 3505 assignment 3.
This test program generates a barnsley fern fractal, which saves the image to a PNG file from pngWriter.
By: Ethan Urowsky
**01/30/2025**
*/

int main(int argc, char* argv[]) {
    //command line argument check
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " output.png width height iterations\n";
        return 1;
    }
    
    //command line arguments
    std::string filename = argv[1]; //PNG filename
    int width = std::atoi(argv[2]); // Image width
    int height = std::atoi(argv[3]); //Image height
    int iterations = std::atoi(argv[4]); //Number of iterations

    //check for valid arguments
    if (width <= 0 || height <= 0 || iterations <= 0) {
        std::cerr << "Invalid arguments.\n";
        return 1;
    }

    PNGWriter writer(width, height); //PNGWriter object

    // Transformations to generate the fern.
    Transform transforms[4] = {
        Transform(0.0, 0.0, 0.0, 0.0, 0.16, 0.0),
        Transform(0.2, -0.26, 0.0, 0.23, 0.22, 1.6),
        Transform(-0.15, 0.28, 0.0, 0.26, 0.24, 0.44),
        Transform(0.85, 0.04, 0.0, -0.04, 0.85, 1.6)
    };

    int probabilities[4] = {1, 7, 7, 85};
    
    Point p(0.0, 0.0); //starting point 

    //iterate and apply the transformations.
    for (int i = 0; i < iterations; i++) {
        int r = rand() % 100, sum = 0, t = 0; // randomly select transformation.
        for (int j = 0; j < 4; j++) {
            sum += probabilities[j];
            if (r < sum) {
                t = j;
                break;
            }
        }
        p = transforms[t] * p; //apply transformation to point.
        
        // Scale coordinates.
        int x = (width / 2) * (1 + p.getX() / 2.75);
        int y = height * (1 - p.getY() / 10.1);

        writer.setPixel(x, y, 0, 255, 0); //green
    }

    writer.writePNGFile(filename); //save image as PNG file.
    return 0;
}
