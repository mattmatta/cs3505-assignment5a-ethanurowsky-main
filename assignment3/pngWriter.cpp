#include "pngWriter.h"
#include <iostream>
#include <fstream>
#include <cstring> 
#include <png.h> 

/*
 * PNGWriter class for CS 3505 Assignment 3.
 * This class is a facade for the libpng library, allowing creation of PNG images and saving the image to a file.
 * By: 
 * Date: 01/30/2025
 */

    /// @brief Constructs a PNGWriter with specified width and height.
    /// @param w - width
    /// @param h - height
PNGWriter::PNGWriter(int w, int h) : width(w), height(h) {
    //image array (3 bytes per pixel for RGB)
    imageData = new unsigned char[width * height * 3];

    // set bytes to 0.
    for (int i = 0; i < width * height * 3; i++) {
        imageData[i] = 0;
    }
}

//Destructor
PNGWriter::~PNGWriter() {
    delete[] imageData;
}

    /// @brief Sets a pixel at (x, y) with RGB values.
    /// @param x - x coordinate.
    /// @param y - y coordinate
    /// @param r - red value
    /// @param g - green value
    /// @param b - blue value
void PNGWriter::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    // check coordinates bounds
    if (x < 0 || x >= width || y < 0 || y >= height)
        return;

    // calculate index for the pixel in the array
    int index = (y * width + x) * 3; // 3 bytes per pixel (R, G, B)

    // set RGB values
    imageData[index] = r;
    imageData[index + 1] = g;
    imageData[index + 2] = b;
}

     /// @brief Writes the image data to a PNG file.
     /// @param filename - Name of PNG file.
     /// @return true if file saved.
bool PNGWriter::writePNGFile(const std::string& filename) {
    FILE* fp = fopen(filename.c_str(), "wb");
    if (!fp) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return false;
    }

    // Initialize libpng structures
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        fclose(fp);
        return false;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_write_struct(&png, nullptr);
        fclose(fp);
        return false;
    }

    if (setjmp(png_jmpbuf(png))) {
        png_destroy_write_struct(&png, &info);
        fclose(fp);
        return false;
    }

    png_init_io(png, fp);

    // Set PNG header
    png_set_IHDR(
        png, info, width, height, 8, 
        PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, 
        PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT
    );

    png_write_info(png, info);

    // convert imageData to row pointers
    png_bytep* rowPointers = new png_bytep[height];
    for (int y = 0; y < height; y++) {
        rowPointers[y] = &imageData[y * width * 3];
    }

    // write image data
    png_write_image(png, rowPointers);
    png_write_end(png, NULL);

    // cleanup
    delete[] rowPointers;
    png_destroy_write_struct(&png, &info);
    fclose(fp);

    return true;
}
