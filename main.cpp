#include <QApplication>
#include "VideoStream.h"

int main(int argc, char** argv) {
    // Create Qt application
    QApplication app(argc, argv);

    // Create VideoStream object
    VideoStream stream;

    // Show the stream widget
    stream.show();

    // Run the Qt event loop
    return app.exec();
}
