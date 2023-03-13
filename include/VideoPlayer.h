#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <opencv2/opencv.hpp>

namespace vv {

	class VideoPlayer : public QWidget {
		Q_OBJECT

	public:
		explicit VideoPlayer(QWidget *parent = nullptr);
		~VideoPlayer();

	protected:
	    void paintEvent(QPaintEvent *event) override;

	private:
		cv::VideoCapture m_cap;
		cv::Mat m_frame;
		QPixmap m_pixmap;
		QTimer m_timer;
		cv::Ptr<cv::AKAZE> m_detector;

	private slots:
		void updateFrame();
	};
}
#endif // VIDEOPLAYER_H
