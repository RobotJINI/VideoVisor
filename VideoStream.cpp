#include "VideoStream.h"
#include <vector>

using namespace cv;

VideoStream::VideoStream(QWidget *parent) : QWidget(parent)
{
    // Open camera
    m_cap.open(0);

    m_detector = AKAZE::create(AKAZE::DESCRIPTOR_MLDB);

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
    // Convert to grayscale
    Mat gray;
    cvtColor(m_frame, gray, COLOR_BGR2GRAY);

    // Detect SURF features
    std::vector<KeyPoint> keypoints;
    m_detector->detect(gray, keypoints);

    // Draw keypoints on input image
    Mat imgKeypoints;
    drawKeypoints(m_frame, keypoints, imgKeypoints);

    // Convert frame to QImage
    QImage img(imgKeypoints.data, imgKeypoints.cols, imgKeypoints.rows, imgKeypoints.step, QImage::Format_RGB888);
    QImage rgbImg = img.rgbSwapped();

    // Set image to label
    m_label.setPixmap(QPixmap::fromImage(rgbImg));

    // Show label
    m_label.show();
}
