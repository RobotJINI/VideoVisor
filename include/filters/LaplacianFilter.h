#ifndef LAPLACIANFILTER_H
#define LAPLACIANFILTER_H

#include "filters/Filter.h"

namespace vv {

	class LaplacianFilter : public Filter {
	public:
		LaplacianFilter() {}
		void apply(cv::Mat& image) override;
	};
}
#endif
