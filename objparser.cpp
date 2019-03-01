#include "objparser.h"

#include <QFile>
#include <qtextstream.h>

OBJParser::OBJParser(const QString &fileName)
{
    mFileName = fileName;
}

void OBJParser::parseFile(const QString &fileName)
{
    if(fileName.isEmpty()){
        return;
    }

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QTextStream data(&file);
    while(!data.atEnd()) {
        QString eachLine = data.readLine();

        if(eachLine.startsWith("v")){
            QStringList dataList = eachLine.split(" ");
            QVector3D tempV;
            tempV.setX(dataList[1].toFloat());
            tempV.setY(dataList[2].toFloat());
            tempV.setZ(dataList[3].toFloat());
            mVertices.push_back(tempV);
        }
        if(eachLine.startsWith("vt")){
            QStringList dataList = eachLine.split(" ");
            QVector2D tempVt;
            tempVt.setX(dataList[1].toFloat());
            tempVt.setY(dataList[2].toFloat());
            mVTextures.push_back(tempVt);
        }
        if(eachLine.startsWith("vn")){
            QStringList dataList = eachLine.split(" ");
            QVector3D tempVn;
            tempVn.setX(dataList[1].toFloat());
            tempVn.setY(dataList[2].toFloat());
            tempVn.setZ(dataList[3].toFloat());
            mVNormals.push_back(tempVn);
        }
        if(eachLine.startsWith("f")){
            Face tempF;
            QStringList dataList = eachLine.split(" ");
            for(int i = 0; i < 3; i++)
            {
                QStringList arg = dataList[i+1].split("/");
                tempF.vertices[i] = mVertices[arg[0].toInt()-1];
                tempF.vTextures[i] = mVTextures[arg[1].toInt()-1];
                tempF.vNormals[i] = mVNormals[arg[2].toInt()-1];
            }
            mFaces.push_back(tempF);
        }
    }

    file.close();

}

QVector<Face> OBJParser::faces() const
{
    return mFaces;
}

QVector<QVector2D> OBJParser::vTextures() const
{
    return mVTextures;
}

QVector<QVector3D> OBJParser::vNormals() const
{
    return mVNormals;
}

QVector<QVector3D> OBJParser::vertices() const
{
    return mVertices;
}
