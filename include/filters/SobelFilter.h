#ifndef SOBELFILTER_H
#define SOBELFILTER_H

#include "filters/Filter.h"

namespace vv {

	class SobelFilter : public Filter {
	public:
		SobelFilter() {}
		void apply(cv::Mat& image) override;
	};
}
#endif
