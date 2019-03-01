#ifndef Q3DOBJHANDLER_H
#define Q3DOBJHANDLER_H

#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>


class Q3DObjHandler:public QObject
{
     Q_OBJECT
public:
    Q3DObjHandler(const QString & filePath);
    ~Q3DObjHandler();

    Qt3DCore::QEntity *get3DModel();

private:
    QString mFilePath;

};

#endif // Q3DOBJHANDLER_H
