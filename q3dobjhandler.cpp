#include "q3dobjhandler.h"
#include <QtCore/QObject>
#include <Qt3DRender/qmesh.h>
#include <QMaterial>
#include <qphongmaterial.h>

Q3DObjHandler::Q3DObjHandler(const QString & filePath)
{
    mFilePath = filePath;
}

Q3DObjHandler::~Q3DObjHandler(){ }

Qt3DCore::QEntity *Q3DObjHandler::get3DModel()
{
    qDebug() << mFilePath;

    Qt3DCore::QEntity *rootScene = new Qt3DCore::QEntity();

    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootScene);

    QUrl data = QUrl::fromLocalFile(mFilePath);
    Qt3DCore::QEntity *chestEntity = new Qt3DCore::QEntity(rootScene);
    Qt3DRender::QMesh *chestMesh = new Qt3DRender::QMesh(rootScene);
    chestMesh->setSource(data);

    chestEntity->addComponent(chestMesh);
    chestEntity->addComponent(material);

    return rootScene;
}
