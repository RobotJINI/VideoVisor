#include "VideoPlayer.h"
#include <vector>
#include <QPainter>
#include "filters/CannyFilter.h"
#include "filters/SurfFilter.h"
#include "filters/LaplacianFilter.h"
#include "filters/SobelFilter.h"
#include "filters/MedianFilter.h"
#include "filters/GaussianFilter.h"

using namespace cv;
using namespace vv;

VideoPlayer::VideoPlayer(QWidget *parent) : QWidget(parent)
{
    // Open camera
    m_cap.open(0);
    // Update camera resolution
    m_cap.set(CAP_PROP_FRAME_WIDTH, width());
    m_cap.set(CAP_PROP_FRAME_HEIGHT, height());

    //m_cur_filter = new CannyFilter(100, 200);
    //m_cur_filter = new SurfFilter();
    //m_cur_filter = new LaplacianFilter();
    //m_cur_filter = new SobelFilter();
    //m_cur_filter = new MedianFilter();
    //m_cur_filter = new GaussianFilter();
    m_cur_filter = new NullFilter();

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
    Mat imgDisplay;
    cv::resize(m_frame, imgDisplay, Size(width(), height()));

    // apply current filter
    m_cur_filter->apply(imgDisplay);

    // Convert frame to QImage
    QImage img(imgDisplay.data, imgDisplay.cols, imgDisplay.rows, imgDisplay.step, QImage::Format_RGB888);
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
