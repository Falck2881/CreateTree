#include "Node.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Node::Node(const QJsonValue value):rect(0.0,0.0,1000.0,1000.0)
{
    Q_INIT_RESOURCE(Images);
    QJsonObject obj = value.toObject();

    _keyNameletter = obj.value(QString("Ansii")).toString();
    QString nameFileImage = obj.value(QString("Image")).toString();
    if(!imageNode.load(nameFileImage))
        qDebug() << "Error: Image file for node not load. >> File Error - Node.cpp - str 14";

    this->setCacheMode(QGraphicsItem::NoCache);
}

QPixmap Node::image() const
{
    return imageNode;
}

QString Node::keyNameLetter() const
{
    return _keyNameletter;
}

const ushort* Node::keyUtf16() const
{
    return _keyNameletter.utf16();
}

void Node::setParentItem(QGraphicsItem *item)
{
    QGraphicsItem::setParentItem(item);
}

void Node::setPos(QPointF newPos)
{
    position = newPos;
}

QPointF Node::pos() const
{
    return this->mapFromScene(position);
}

QRectF Node::boundingRect() const
{
    return rect;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    const QRectF sourceRect(0,0,imageNode.width(),imageNode.height());
    painter->drawPixmap(position,imageNode,sourceRect);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}
