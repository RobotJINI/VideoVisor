#include <QApplication>
#include "VideoVisor.h"

int main(int argc, char** argv) {
    // Create Qt application
    QApplication app(argc, argv);

    // Create VideoStream object
    vv::VideoVisor videoVisor;

    // Show the stream widget
    videoVisor.show();

    // Run the Qt event loop
    return app.exec();
}
