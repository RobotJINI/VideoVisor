#ifndef FILTER_H
#define FILTER_H

#include <opencv2/opencv.hpp>

namespace vv {

	class Filter {
	public:
		virtual ~Filter() {}
		virtual void apply(cv::Mat& image) = 0;
	};

	class NullFilter : public Filter {
	public:
		NullFilter() {}
		void apply(cv::Mat& image [[maybe_unused]]) override {}
	};
}
#endif
