#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

#include "filters/Filter.h"

namespace vv {

	class MedianFilter : public Filter {
	public:
		MedianFilter() {}
		void apply(cv::Mat& image) override;
	};
}
#endif
