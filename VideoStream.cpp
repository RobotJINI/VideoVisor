#include "VideoStream.h"

using namespace cv;

VideoStream::VideoStream(QWidget *parent) : QWidget(parent)
{
    // Open camera
    m_cap.open(0);

    // Set camera resolution
    m_cap.set(CAP_PROP_FRAME_WIDTH, 640);
    m_cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    // Set up label
    m_label.setFixedSize(640, 480);

    // Set up timer
    connect(&m_timer, &QTimer::timeout, this, &VideoStream::updateFrame);
    m_timer.start(20);
}

VideoStream::~VideoStream()
{
    m_cap.release();
}

void VideoStream::updateFrame()
{
    // Read frame from camera
    if (!m_cap.read(m_frame)) {
        m_timer.stop();
        return;
    }

    // Convert frame to QImage
    QImage img(m_frame.data, m_frame.cols, m_frame.rows, m_frame.step, QImage::Format_RGB888);
    QImage rgbImg = img.rgbSwapped();

    // Set image to label
    m_label.setPixmap(QPixmap::fromImage(rgbImg));

    // Show label
    m_label.show();
}
