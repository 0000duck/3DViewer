#ifndef OBJPARSER_H
#define OBJPARSER_H

#include <QObject>
#include <QVector>
#include <QVector3D>
#include <QVector2D>

struct Face{
    QVector<QVector3D> vertices;
    QVector<QVector3D> vNormals;
    QVector<QVector2D> vTextures;
};
class OBJParser
{
public:
    OBJParser(const QString &fileName);
    QVector<QVector3D> vertices() const;

    QVector<QVector3D> vNormals() const;

    QVector<QVector2D> vTextures() const;

    QVector<Face> faces() const;

private:
    void parseFile(const QString &fileName);
private:
    QString mFileName;
    QVector<QVector3D> mVertices;
    QVector<QVector3D> mVNormals;
    QVector<QVector2D> mVTextures;
    QVector<Face> mFaces;
};

#endif // OBJPARSER_H
