#include "VideoPlayer.h"
#include <vector>
#include <QPainter>
#include <QDebug>
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
    if (!m_cap.open(0)) {
        qWarning() << "Failed to open camera";
    }
    // Update camera resolution
    m_cap.set(CAP_PROP_FRAME_WIDTH, width());
    m_cap.set(CAP_PROP_FRAME_HEIGHT, height());

    m_cur_filter = std::make_unique<NullFilter>();

    // Set up timer
    connect(&m_timer, &QTimer::timeout, this, &VideoPlayer::updateFrame);
    m_timer.start(20);
}

VideoPlayer::~VideoPlayer()
{
    m_cap.release();
}

void VideoPlayer::switchFilter(const std::string& filterName) {
    if (filterName == "Canny") {
        m_cur_filter = std::make_unique<CannyFilter>(100, 200);
    } else if (filterName == "Surf") {
        m_cur_filter = std::make_unique<SurfFilter>();
    } else if (filterName == "Laplacian") {
        m_cur_filter = std::make_unique<LaplacianFilter>();
    } else if (filterName == "Sobel") {
        m_cur_filter = std::make_unique<SobelFilter>();
    } else if (filterName == "Median") {
        m_cur_filter = std::make_unique<MedianFilter>();
    } else if (filterName == "Gaussian") {
        m_cur_filter = std::make_unique<GaussianFilter>();
    } else {
    	m_cur_filter = std::make_unique<NullFilter>();
    }
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
