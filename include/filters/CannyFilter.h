#ifndef CANNYFILTER_H
#define CANNYFILTER_H

#include "filters/Filter.h"

namespace vv {

	class CannyFilter : public Filter {
	public:
		CannyFilter(double low_threshold, double high_threshold);
		void apply(cv::Mat& image) override;

	private:
		double m_low_threshold;
		double m_high_threshold;
	};
}
#endif
