#include "filters/SobelFilter.h"

using namespace vv;

void SobelFilter::apply(cv::Mat& image)
{
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    cv::Mat grad_x, grad_y;
    cv::Sobel(gray_image, grad_x, CV_16S, 1, 0);
    cv::Sobel(gray_image, grad_y, CV_16S, 0, 1);
    cv::Mat abs_grad_x, abs_grad_y;
    cv::convertScaleAbs(grad_x, abs_grad_x);
    cv::convertScaleAbs(grad_y, abs_grad_y);
    cv::Mat grad_image;
    cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad_image);

    cv::cvtColor(grad_image, image, cv::COLOR_GRAY2BGR);
}
