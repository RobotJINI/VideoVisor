#include "filters/SurfFilter.h"

using namespace vv;
using namespace cv;

SurfFilter::SurfFilter()
{
	m_detector = AKAZE::create(AKAZE::DESCRIPTOR_MLDB);
}

void SurfFilter::apply(cv::Mat& image)
{
    // Convert to grayscale
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // Detect SURF features
    std::vector<KeyPoint> keypoints;
    m_detector->detect(gray, keypoints);

    // Draw keypoints on input image
    drawKeypoints(image, keypoints, image);
}
