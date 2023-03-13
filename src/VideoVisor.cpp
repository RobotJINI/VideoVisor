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
    videoPlayer = new VideoPlayer();

    // Create the layout for the toggle buttons
    QVBoxLayout *toggleButtonLayout = new QVBoxLayout();
    createToggleButtonLayout(toggleButtonLayout);

    // Create the layout for the video player and toggle buttons
    QHBoxLayout *videoLayout = new QHBoxLayout();
    videoLayout->addWidget(videoPlayer);
    videoLayout->addLayout(toggleButtonLayout);

    // Create the main widget
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(videoLayout);

    // Set the main widget as the central widget of the main window
    setCentralWidget(mainWidget);

    // Connect the signals and slots for the buttons
    connect(resolutionCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &VideoVisor::updateResolution);

    // Set the window title and size
    setWindowTitle("Video Visor");
    this->setFixedSize(640 + 150, 480);
}

void VideoVisor::createToggleButtonLayout(QVBoxLayout *toggleButtonLayout) {
    // set the size of each toggle button
    QSize buttonSize(150, 50);

    // Create resolution comboBox
    resolutionCombo = new QComboBox(this);
    resolutionCombo->setFixedSize(buttonSize);
    resolutionCombo->addItem("640x480");
    resolutionCombo->addItem("800x600");
    resolutionCombo->addItem("1024x768");

    // Add the buttons to the layout
    toggleButtonLayout->addWidget(resolutionCombo);
    toggleButtonLayout->setSpacing(0);
}

void VideoVisor::updateResolution(int index)
{
    switch (index) {
    case 0:
        videoPlayer->resize(640, 480);
        this->setFixedSize(640 + 150, 480);
        break;
    case 1:
        videoPlayer->resize(800, 600 );
        this->setFixedSize(800 + 150, 600);
        break;
    case 2:
        videoPlayer->resize(1024, 768);
        this->setFixedSize(1024 + 150, 768);
        break;
    }
}
