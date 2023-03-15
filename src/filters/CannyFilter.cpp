#include "filters/CannyFilter.h"

using namespace vv;

CannyFilter::CannyFilter(double low_threshold, double high_threshold) :
    m_low_threshold(low_threshold), m_high_threshold(high_threshold) {}

void CannyFilter::apply(cv::Mat& image)
{
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    cv::Mat edges_image;
    cv::Canny(gray_image, edges_image, m_low_threshold, m_high_threshold);
    cv::cvtColor(edges_image, image, cv::COLOR_GRAY2BGR);
}
