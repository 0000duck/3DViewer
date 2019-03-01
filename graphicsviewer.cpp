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
    ui->setupUi(mContainer);
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
    mCamera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    mCamera->setPosition(QVector3D(0, 0, 1));
    mCamera->setViewCenter(QVector3D(0, 0, 0));
}

void GraphicsViewer::setCameraControl()
{
    mCamController->setLinearSpeed( 10.0f );
    mCamController->setLookSpeed( 180.0f );
    mCamController->setCamera(mCamera);
}


