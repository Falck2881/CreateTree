#include "GraphicsNode.h"
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

GraphicsNode::GraphicsNode(const QJsonValue value):position(0.0,0.0),boundingRectDisplayItem(0.0,0.0,2000.0,1600.0)
{
    Q_INIT_RESOURCE(Images);
    QJsonObject obj = value.toObject();

    _keyNameletter = obj.value(QString("Ansii")).toString();
    QString nameFileImage = obj.value(QString("Image")).toString();
    if(!imageNode.load(nameFileImage))
        qDebug() << "Error: Image file for node not load. >> File Error - Node.cpp - str 14";

    this->setCacheMode(QGraphicsItem::NoCache);
}

QPixmap GraphicsNode::image() const
{
    return imageNode;
}

QRectF GraphicsNode::rectItem() const
{
    return _rectItem;
}

QString GraphicsNode::keyNameLetter() const
{
    return _keyNameletter;
}

uint GraphicsNode::key() const
{
    bool ok;
    uint key = _keyNameletter.toUInt(&ok,16);
    return key;
}

void GraphicsNode::setParent(QGraphicsItem *item)
{
    this->setParentItem(item);
}

void GraphicsNode::updatePos(QPointF newPos)
{
    position = newPos;
    _rectItem.setCoords(position.x(),position.y(),position.x()+40.0,position.y()+40.0);
}

QPointF GraphicsNode::pos() const
{
    return this->mapFromScene(position);
}

qreal GraphicsNode::topRightX() const
{
    return _rectItem.topRight().x();
}

qreal GraphicsNode::topRightY() const
{
    return _rectItem.topRight().y();
}

QRectF GraphicsNode::boundingRect() const
{
    return boundingRectDisplayItem;
}

void GraphicsNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    const QRectF sourceRect(0,0,imageNode.width(),imageNode.height());
    painter->drawPixmap(position,imageNode,sourceRect);
}

void GraphicsNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

GraphicsNode& GraphicsNode::operator=(GraphicsNode* const old)
{
    if(this == old)
        return *this;

    this->imageNode = old->imageNode;
    this->position = old->position;
    this->_keyNameletter = old->_keyNameletter;
    this->boundingRectDisplayItem = old->boundingRectDisplayItem;

    return *this;
}
