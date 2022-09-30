#include "Builder.h"
#include <QGraphicsLineItem>

Builder::Builder():graphicsTree(std::make_unique<GraphicsTree>())
{
}

QGraphicsScene* Builder::scene() const
{
    return graphicsTree->scene();
}
