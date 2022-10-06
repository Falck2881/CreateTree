#include "GraphicsBuilder.h"
#include <QGraphicsLineItem>

GraphicsBuilder::GraphicsBuilder():sceneNode(std::make_unique<QGraphicsScene>(QRectF(0.0,0.0,1200.0,1200.0))),index{0}
{
    initializeArrayOffsetBranch();
}

void GraphicsBuilder::initializeArrayOffsetBranch()
{
    qreal ratioAxesX2 = 2.4;
    qreal ratioAxesY2 = 4.4;
    const quint32 size{10};
    QPointF leftOffsetByAxesXY2(220.0,44.0);
    QPointF rightOffsetByAxesXY2(260.0,44.0);

    for(quint32 index = 0; index < size; ++index)
    {
        arrayOffsetBranch.push_back(std::make_pair(leftOffsetByAxesXY2,rightOffsetByAxesXY2));
        leftOffsetByAxesXY2.setX(leftOffsetByAxesXY2.x() / ratioAxesX2);
        leftOffsetByAxesXY2.setY(leftOffsetByAxesXY2.y() + ratioAxesY2);
        rightOffsetByAxesXY2.setX(rightOffsetByAxesXY2.x() / ratioAxesX2);
        rightOffsetByAxesXY2.setY(rightOffsetByAxesXY2.y() + ratioAxesY2);
        ratioAxesX2 -= 0.2;
        ratioAxesY2 += 1.2;
    }
}

QGraphicsScene* GraphicsBuilder::scene() const
{
    return sceneNode.get();
}

void GraphicsBuilder::incrementIndex()
{
    ++index;
}

void GraphicsBuilder::decrimentIndex()
{
    if(index != 0)
        --index;
}
