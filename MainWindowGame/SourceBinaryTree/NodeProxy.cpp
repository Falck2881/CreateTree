#include "NodeProxy.h"
#include "StreamJson.h"
#include <QJsonObject>

NodeProxy::NodeProxy(const QJsonValue value):node(nullptr)
{
    QString key = extractKey(value);
    QString nameFileImage = extractNameFileImg(value);
    pair = std::make_pair(key,nameFileImage);
}

QString NodeProxy::extractKey(const QJsonValue &value)
{
    QJsonObject obj = value.toObject();
    return obj.value(QString("Ansii")).toString();
}

QString NodeProxy::extractNameFileImg(const QJsonValue &value)
{
    QJsonObject obj = value.toObject();
    return obj.value(QString("Image")).toString();
}

void NodeProxy::draw()
{

}
