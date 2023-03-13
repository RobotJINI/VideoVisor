#ifndef VIDEOVISOR_H
#define VIDEOVISOR_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QComboBox>
#include "VideoPlayer.h"

namespace vv {

	class VideoVisor : public QMainWindow
	{
		Q_OBJECT

	public:
		VideoVisor(QWidget *parent = nullptr);

	private slots:
		void updateResolution(int index);

	private:
		VideoPlayer *videoPlayer;
		QComboBox *resolutionCombo;

		void createToggleButtonLayout(QVBoxLayout *toggleButtonLayout);
	};
}

#endif // VIDEOVISOR_H
