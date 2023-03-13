#include <QApplication>
#include "VideoPlayer.h"

int main(int argc, char** argv) {
    // Create Qt application
    QApplication app(argc, argv);

    // Create VideoStream object
    vv::VideoPlayer player;

    // Show the stream widget
    player.show();

    // Run the Qt event loop
    return app.exec();
}
