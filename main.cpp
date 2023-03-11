#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // Open default camera
    VideoCapture cap(0);

    // Check if camera is opened
    if (!cap.isOpened()) {
        cerr << "Could not open camera." << endl;
        return -1;
    }

    // Set camera resolution
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    // Create SURF object
    Ptr<AKAZE> detector = AKAZE::create(AKAZE::DESCRIPTOR_MLDB);

    // Loop through frames
    while (true) {
        // Read frame from camera
        Mat frame;
        cap.read(frame);

        // Detect keypoints and extract descriptors
        vector<KeyPoint> keypoints;
        Mat descriptors;
        detector->detectAndCompute(frame, noArray(), keypoints, descriptors);

        // Print number of keypoints and descriptors
        cout << "Number of keypoints: " << keypoints.size() << endl;
        cout << "Number of descriptors: " << descriptors.rows << endl;

        // Convert to grayscale using nonlinear conversion
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        gray = gray.mul(gray) / 255;

        // Check if frame is empty
        if (frame.empty()) {
            cerr << "Could not read frame." << endl;
            break;
        }

        // Display frame
        imshow("Camera", gray);

        // Wait for key press
        if (waitKey(1) == 27) {
            break;
        }
    }

    // Release camera
    cap.release();

    return 0;
}
