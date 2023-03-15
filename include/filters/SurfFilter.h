#ifndef SURFFILTER_H
#define SURFFILTER_H

#include "filters/Filter.h"
#include <opencv2/opencv.hpp>

namespace vv {

	class SurfFilter : public Filter {
	public:
		SurfFilter();
		void apply(cv::Mat& image) override;
	private:
		cv::Ptr<cv::AKAZE> m_detector;
	};
}
#endif
