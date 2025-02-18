#ifndef PNGWRITER_H
#define PNGWRITER_H
#include <string>

/*
 * PNGWriter class for CS 3505 Assignment 3.
 * This class is a facade for the libpng library, allowing creation of PNG images and saving the image to a file.
 * By: 
 * Date: 01/30/2025
 */

class PNGWriter {
private:
    int width, height;           // image dimensions
    unsigned char* imageData;    // image data array for pixel storage

public:
    /// @brief Initializes the image with a given width and height.
    /// @param w - Width of the image.
    /// @param h - Height of the image.
    PNGWriter(int w, int h);

    //Destructor
    ~PNGWriter();

    /// @brief Sets a pixel at (x, y) with RGB values.
    /// @param x - x coordinate.
    /// @param y - y coordinate
    /// @param r - red value
    /// @param g - green value
    /// @param b - blue value
    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

     /// @brief Writes the image data to a PNG file.
     /// @param filename - Name of PNG file.
     /// @return true if file saved.
     bool writePNGFile(const std::string& filename);
};
#endif