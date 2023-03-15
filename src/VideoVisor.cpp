#include "VideoVisor.h"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

using namespace vv;

VideoVisor::VideoVisor(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the video player
    m_videoPlayer = new VideoPlayer();
    m_buttonSize = new QSize(150, 50);
    m_labelSize = new QSize(100, 50);
    createUI();
}

void VideoVisor::createUI()
{
    // Create the layout for the toggle buttons
    QVBoxLayout *toggleButtonLayout = new QVBoxLayout();
    createToggleButtonLayout(toggleButtonLayout);
    createFilterButtonLayout(toggleButtonLayout);
    toggleButtonLayout->setSpacing(0);
    toggleButtonLayout->setAlignment(Qt::AlignTop);

    // Create the layout for the video player and toggle buttons
    QHBoxLayout *videoLayout = new QHBoxLayout();
    videoLayout->addWidget(m_videoPlayer);
    videoLayout->addLayout(toggleButtonLayout);

    // Create the main widget
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(videoLayout);

    // Set the main widget as the central widget of the main window
    setCentralWidget(mainWidget);

    // Connect the signals and slots for the buttons
    connect(m_resolutionCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &VideoVisor::updateResolution);
    connect(m_filterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &VideoVisor::onFilterChanged);

    // Set the window title and size
    setWindowTitle("Video Visor");
    updateResolution(0);
}

void VideoVisor::createToggleButtonLayout(QVBoxLayout *toggleButtonLayout)
{
	QHBoxLayout *internal_layout = new QHBoxLayout();
	QLabel *label = new QLabel("Resolution:");
	label->setFixedSize(*m_labelSize);
	internal_layout->addWidget(label);

    m_resolutionCombo = new QComboBox(this);
    m_resolutionCombo->setFixedSize(*m_buttonSize);
    m_resolutionCombo->addItem("640x480");
    m_resolutionCombo->addItem("800x600");
    m_resolutionCombo->addItem("1024x768");

    internal_layout->addWidget(m_resolutionCombo);
    internal_layout->setSpacing(0);

    toggleButtonLayout->addLayout(internal_layout);
}

void VideoVisor::createFilterButtonLayout(QVBoxLayout *toggleButtonLayout)
{
	QHBoxLayout *internal_layout = new QHBoxLayout();
	QLabel *label = new QLabel("Filter:");
	label->setFixedSize(*m_labelSize);
	internal_layout->addWidget(label);

	m_filterCombo = new QComboBox(this);
	m_filterCombo->setFixedSize(*m_buttonSize);
	m_filterCombo->addItem("None");
	m_filterCombo->addItem("Gaussian");
	m_filterCombo->addItem("Median");
	m_filterCombo->addItem("Sobel");
	m_filterCombo->addItem("Laplacian");
    m_filterCombo->addItem("Canny");
    m_filterCombo->addItem("Surf");

    internal_layout->addWidget(m_filterCombo);
    internal_layout->setSpacing(0);

    toggleButtonLayout->addLayout(internal_layout);
}

void VideoVisor::onFilterChanged(int index)
{
    QString filterName = m_filterCombo->itemText(index);
    m_videoPlayer->switchFilter(filterName.toStdString());
}

void VideoVisor::updateResolution(int index)
{
    switch (index) {
    case 0:
    	m_videoPlayer->resize(640, 480);
        this->setFixedSize(getWindowWidth(640), 480);
        break;
    case 1:
    	m_videoPlayer->resize(800, 600 );
        this->setFixedSize(getWindowWidth(800), 600);
        break;
    case 2:
    	m_videoPlayer->resize(1024, 768);
        this->setFixedSize(getWindowWidth(1024), 768);
        break;
    }
}

int VideoVisor::getWindowWidth(int video_width)
{
	return video_width + m_buttonSize->width() + m_labelSize->width();
}
