#include "Builder.h"
#include <QGraphicsLineItem>

Builder::Builder():graphicsScene(std::make_unique<GraphicsSceneNode>())
{
}

QGraphicsScene* Builder::scene() const
{
    return graphicsScene->scene();
}
