#include "VideoPlayer.h"
#include <vector>
#include <QPainter>

using namespace cv;
using namespace vv;

VideoPlayer::VideoPlayer(QWidget *parent) : QWidget(parent)
{
    // Open camera
    m_cap.open(0);

    m_detector = AKAZE::create(AKAZE::DESCRIPTOR_MLDB);

    // Update camera resolution
    m_cap.set(CAP_PROP_FRAME_WIDTH, width());
    m_cap.set(CAP_PROP_FRAME_HEIGHT, height());

    // Set up timer
    connect(&m_timer, &QTimer::timeout, this, &VideoPlayer::updateFrame);
    m_timer.start(20);
}

VideoPlayer::~VideoPlayer()
{
    m_cap.release();
}

void VideoPlayer::updateFrame()
{
    // Read frame from camera
    if (!m_cap.read(m_frame)) {
        //m_timer.stop();
        return;
    }
    // Resize frame to fit widget size
    Mat resizedFrame;
    cv::resize(m_frame, resizedFrame, Size(width(), height()));

    // Convert to grayscale
    Mat gray;
    cvtColor(resizedFrame, gray, COLOR_BGR2GRAY);

    // Detect SURF features
    std::vector<KeyPoint> keypoints;
    m_detector->detect(gray, keypoints);

    // Draw keypoints on input image
    Mat imgKeypoints;
    drawKeypoints(resizedFrame, keypoints, imgKeypoints);

    // Convert frame to QImage
    QImage img(imgKeypoints.data, imgKeypoints.cols, imgKeypoints.rows, imgKeypoints.step, QImage::Format_RGB888);
    QImage rgbImg = img.rgbSwapped();

    // Set image to label
    m_pixmap = QPixmap::fromImage(rgbImg);
    update();
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
void VideoPlayer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
}
