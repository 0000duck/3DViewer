#ifndef GRAPHICSVIEWER_H
#define GRAPHICSVIEWER_H

#include <QWidget>
#include <QCamera>
#include <QOrbitCameraController>
#include <qt3dwindow.h>

#include "q3dobjhandler.h"

namespace Ui {
class GraphicsViewer;
}

class GraphicsViewer : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsViewer(QWidget *parent = nullptr, const QString& filePath="default");
    ~GraphicsViewer();
private:
    void setCamera(const Qt3DExtras::Qt3DWindow* view);
    void setCameraControl();

private:
    Ui::GraphicsViewer *ui;
    QWidget* mContainer;
    Q3DObjHandler* mHandler;
    Qt3DRender::QCamera *mCamera;
    Qt3DExtras::QOrbitCameraController *mCamController;
    Qt3DCore::QEntity *mScene ;
    Qt3DExtras::Qt3DWindow* mView;
};

#endif // GRAPHICSVIEWER_H
