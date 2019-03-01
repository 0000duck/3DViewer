#include "graphicsviewer.h"
#include "ui_graphicsviewer.h"

#include <qt3dwindow.h>

GraphicsViewer::GraphicsViewer(QWidget *parent,const QString& filePath) :
    QWidget(parent),
    ui(new Ui::GraphicsViewer)
{
    ui->setupUi(this);

    mHandler = new Q3DObjHandler(filePath);
    Qt3DExtras::Qt3DWindow* view = new Qt3DExtras::Qt3DWindow();

    mScene = mHandler->get3DModel();
    mCamController = new Qt3DExtras::QOrbitCameraController(mScene);

    setCamera(view);
    setCameraControl();

    view->setRootEntity(mScene);
    mContainer=createWindowContainer(view, this);
    mContainer->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    mContainer->setWindowState(mContainer->windowState() | Qt::WindowFullScreen);
    mContainer->setWindowTitle("3d Viewer");
    ui->setupUi(mContainer);
    mContainer->showFullScreen();
}

GraphicsViewer::~GraphicsViewer()
{
    delete ui;
    mContainer->deleteLater();
    mHandler->deleteLater();
    mCamera->deleteLater();
    mCamController->deleteLater();
}

void GraphicsViewer::setCamera(const  Qt3DExtras::Qt3DWindow* view)
{
    mCamera = view->camera();
    mCamera->lens()->setPerspectiveProjection(50.0f, 2.0f, 0.5f, 1000.0f);
    mCamera->setPosition(QVector3D(0, 0, 25));
    mCamera->setViewCenter(QVector3D(0, 0, 0));
}

void GraphicsViewer::setCameraControl()
{
    mCamController->setLinearSpeed( 10.0f );
    mCamController->setLookSpeed( 180.0f );
    mCamController->setCamera(mCamera);
}


