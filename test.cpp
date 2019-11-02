#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main(int argc, char** argv) {
    Mat raw_image, cur_image;
    if (argc == 1) {
        VideoCapture camera(0);
        if (!camera.read(raw_image)) {
            cout << "Could not capture image from camera" << endl;
            return -1;
        }
    } else {
        raw_image = imread(samples::findFile(argv[1]),
                           IMREAD_COLOR);  // Read the file
        if (raw_image.empty())             // Check for invalid input
        {
            cout << "Could not open or find the image" << std::endl;
            return -1;
        }
    }
    // auto original_image = image;
    // image = (image, COLOR_BGR2GRAY);
    namedWindow("Display window",
                WINDOW_NORMAL);           // Create a window for display.
    imshow("Display window", raw_image);  // Show our image inside it.
    int key = waitKey(0);                 // Wait for a keystroke in the window
    do {
        switch (key) {
            case 'i': {
                cur_image = raw_image;
                break;
            }
            case 'w': {
                imwrite("out.jpg", cur_image);
                break;
            }
            case 'g':
                cvtColor(raw_image, cur_image, COLOR_BGR2GRAY);
                break;
            default:
                break;
        }
        imshow("Display window", cur_image);  // Show our image inside it.
    } while ((key = waitKey(0)) != 'q');
    return 0;
}