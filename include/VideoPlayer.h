#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "filters/Filter.h"

namespace vv {

	class VideoPlayer : public QWidget {
		Q_OBJECT

	public:
		explicit VideoPlayer(QWidget *parent = nullptr);
		~VideoPlayer();

		void switchFilter(const std::string& filterName);

	protected:
	    void paintEvent(QPaintEvent *event) override;

	private:
		cv::VideoCapture m_cap;
		cv::Mat m_frame;
		QPixmap m_pixmap;
		QTimer m_timer;
		std::unique_ptr<Filter> m_cur_filter;

	private slots:
		void updateFrame();
	};
}
#endif // VIDEOPLAYER_H
