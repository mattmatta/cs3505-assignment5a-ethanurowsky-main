/*
Ethan Urowsky
Barnsley Fern: a fractal named after Michael Barnsley, generated with an iterated function system(IFS). Draws image of a fern.
01/17/2025
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int width = 128;    // set width as desired
const int height = 150;   // set height as desired as long as width * height is a multiple of 8
const double xMax = 2.75; // DO NOT CHANGE
const double yMax = 10.1; // DO NOT CHANGE

const int probabilities[4] = {1, 7, 7, 85};
const double transformations[4][6] = {
    {0.0, 0.0, 0.0, 0.0, 0.16, 0.0},
    {0.2, -0.26, 0.0, 0.23, 0.22, 1.6},
    {-0.15, 0.28, 0.0, 0.26, 0.24, 0.44},
    {0.85, 0.04, 0.0, -0.04, 0.85, 1.6}
};

void performIterations(int iterations, unsigned char* image);
int selectTransformation();
void applyTransformation(double& x, double& y, const double* transformation);
void setPixel(double x, double y, unsigned char* image);
bool getPixel(int row, int col, unsigned char* image);
void drawImage(unsigned char* image);

int main() {
    //prompt user.
    int numIterations;
    cout << "How many iterations:" << endl;
    cin >> numIterations;

    //iterations has to be positive.
    if (numIterations <= 0) {
        cout << "Number of iterations must be positive" << endl;
        return 0;
    }

    // initialize the array.
    int size = (width * height) / 8;
    unsigned char* image = new unsigned char[size]();

    // perform the iterations.
    performIterations(numIterations, image);

    // draw the image.
    drawImage(image);

    // delete from mem.
    delete[] image;
    return 0;
}
/*
Performs the specified number of iterations by repeatedly selecting a transformation function,
applying that transformation, and setting the pixel based on the resulting x and y values.
*/
void performIterations(int iterations, unsigned char* image) {
    //set x and y.
    double x = 0.0, y = 0.0;
    //loop for specified number of iterations.
    for (int i = 0; i < iterations; i++) {
        int t = selectTransformation();
        applyTransformation(x, y, transformations[t]);
        setPixel(x, y, image);
    }
}

/*
Randomly selects one of the four transformations with the corresponding probabilities, returning 0, 1, 2, or 3.
*/
int selectTransformation() {
    //random number between 0 and 99.
    int random = rand() % 100;
    int sum = 0;
    //loop through transformations.
    for (int i = 0; i < 4; i++) {
        sum += probabilities[i];
        if (random < sum) {
            return i; // returns 0,1,2 or 3.
        }
    }
    return 3; // default
}

/*
The given transformation is applied to the values in x and y. The resulting values are stored in the same x and y variables.
*/
void applyTransformation(double& x, double& y, const double* transformation) {
    double transformationX = transformation[0] * x + transformation[1] * y + transformation[2];
    double transformationY = transformation[3] * x + transformation[4] * y + transformation[5];
    //update x and y.
    x = transformationX;
    y = transformationY;
}

/*
Sets the pixel that contains the point (x, y) to be drawn in the image.
*/
void setPixel(double x, double y, unsigned char* image) {
    //set to pixel coordinates.
    int pixelX = (int)(width / 2 * (1 + x / xMax));
    int pixelY = (int)(height * (1 - y / yMax));
    //out of bounds check.
    if (pixelX < 0 || pixelX >= width || pixelY < 0 || pixelY >= height) return;
    //calculate and set.
    int index = (pixelY * width + pixelX) / 8;
    int bit = (pixelY * width + pixelX) % 8;
    image[index] |= (1 << bit);
}

/*
Returns true if the pixel at the given row and column in the image is set. In other words, that bit has value 1.
Returns false if that bit is zero.
*/
bool getPixel(int row, int col, unsigned char* image) {
    //calculate and return if bit is set.
    int index = (row * width + col) / 8;
    int bit = (row * width + col) % 8;
    return image[index] & (1 << bit);
}

/*
Draw the image one row at a time by printing to the terminal.
*/
void drawImage(unsigned char* image) {
    //loop through row and column.
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            //print
            if (getPixel(row, col, image)) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}