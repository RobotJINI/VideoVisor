#include "filters/GaussianFilter.h"

using namespace vv;

void GaussianFilter::apply(cv::Mat& image)
{
    cv::Mat blurred_image;
    cv::GaussianBlur(image, image, cv::Size(5, 5), 0);
}
