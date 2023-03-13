#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <opencv2/opencv.hpp>

namespace vv {

	class VideoPlayer : public QWidget {
		Q_OBJECT

	public:
		explicit VideoPlayer(QWidget *parent = nullptr);
		~VideoPlayer();

	private:
		cv::VideoCapture m_cap;
		cv::Mat m_frame;
		QLabel m_label;
		QTimer m_timer;
		cv::Ptr<cv::AKAZE> m_detector;

	private slots:
		void updateFrame();
	};
}
#endif // VIDEOPLAYER_H
