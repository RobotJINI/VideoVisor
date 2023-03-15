#include "filters/MedianFilter.h"

using namespace vv;

void MedianFilter::apply(cv::Mat& image)
{
    cv::Mat median_image;
    cv::medianBlur(image, image, 5);
}
