#include "GraphicsBuilder.h"

GraphicsBuilder::GraphicsBuilder(const QString methodBuild):
    method(methodBuild),
    sceneDisplayTree(std::make_unique<QGraphicsScene>(QRectF(0.0,0.0,1300.0,1200.0)))
{
}

QString GraphicsBuilder::methodBuild() const
{
    return method;
}

QGraphicsScene* GraphicsBuilder::scene()
{
    return sceneDisplayTree.get();
}
