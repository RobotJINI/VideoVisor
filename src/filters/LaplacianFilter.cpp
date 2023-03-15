#include "filters/LaplacianFilter.h"

using namespace vv;

void LaplacianFilter::apply(cv::Mat& image)
{
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
    cv::Mat laplacian_image;
    cv::Laplacian(gray_image, laplacian_image, CV_16S);
    cv::Mat abs_laplacian_image;
    cv::convertScaleAbs(laplacian_image, abs_laplacian_image);

    cv::cvtColor(abs_laplacian_image, image, cv::COLOR_GRAY2BGR);
}
