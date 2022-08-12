#include "Node.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Node::Node(const QJsonValue value)
{
    Q_INIT_RESOURCE(Images);
    QJsonObject obj = value.toObject();

    _key = obj.value(QString("Ansii")).toString();
    QString nameFileImage = obj.value(QString("Image")).toString();
    if(!imageNode.load(nameFileImage))//<-- Look carefully at the sign
        qDebug() << "Error: Image file for node not load. >> File Error - Node.cpp - str 12";
}

const char16_t Node::key() const
{
    return _key.unicode()->unicode();
}

QRectF Node::boundingRect() const
{
    return QRectF(-40.0,-40.0,40,40);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPointF point(235.0,230.0);
    const QRectF sourceRect(0,0,imageNode.width(),imageNode.height());
    painter->drawPixmap(point,imageNode,sourceRect);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}
