#include "GraphicsBuilder.h"
#include <QGraphicsLineItem>

GraphicsBuilder::GraphicsBuilder():sceneNode(std::make_unique<QGraphicsScene>(QRectF(0.0,0.0,1200.0,1200.0)))
{

}

QGraphicsScene* GraphicsBuilder::scene() const
{
    return sceneNode.get();
}
