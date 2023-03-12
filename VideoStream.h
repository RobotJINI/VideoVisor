#ifndef VIDEOSTREAM_H
#define VIDEOSTREAM_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <opencv2/opencv.hpp>

class VideoStream : public QWidget {
    Q_OBJECT

public:
    explicit VideoStream(QWidget *parent = nullptr);
    ~VideoStream();

private:
    cv::VideoCapture m_cap;
    cv::Mat m_frame;
    QLabel m_label;
    QTimer m_timer;

private slots:
    void updateFrame();
};

#endif // VIDEOSTREAM_H
