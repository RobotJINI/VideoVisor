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
		VideoPlayer *m_videoPlayer;
		QComboBox *m_resolutionCombo;
		QComboBox *m_filterCombo;
		QSize *m_buttonSize;
		QSize *m_labelSize;

		void createUI();
		void createToggleButtonLayout(QVBoxLayout *toggleButtonLayout);
		void createFilterButtonLayout(QVBoxLayout *toggleButtonLayout);
		int getWindowWidth(int video_width);
	};
}

#endif // VIDEOVISOR_H
