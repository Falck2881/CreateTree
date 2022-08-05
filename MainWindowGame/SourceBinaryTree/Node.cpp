#include "Node.h"
#include <QDebug>

Node::Node()
{
    Q_INIT_RESOURCE(Images);
}

void Node::setData(const QJsonObject obj)
{
    _key = obj.value(QString("Ansii")).toString();
    QString nameFileImage = obj.value(QString("Image")).toString();
    if(!imageNode.load(nameFileImage))//<-- Look carefully at the sign
        qDebug() << "Error: Image file for node not load. >> File Error - Node.cpp - str 9";
}

const char16_t Node::key() const
{
    return _key.unicode()->unicode();
}
