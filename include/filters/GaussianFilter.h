#ifndef GAUSSIANFILTER_H
#define GAUSSIANFILTER_H

#include "filters/Filter.h"

namespace vv {

	class GaussianFilter : public Filter {
	public:
		GaussianFilter() {}
		void apply(cv::Mat& image) override;
	};
}
#endif
