#include "GraphicsSceneNode.h"

GraphicsSceneNode::GraphicsSceneNode():sceneNode(std::make_unique<QGraphicsScene>(QRectF(0.0,0.0,1000.0,1000.0))),
                                       coordinate(500.0,10.0)
{

}

QPointF GraphicsSceneNode::coordinateNode() const
{
    return coordinate;
}

void GraphicsSceneNode::addItem(QGraphicsItem *const item)
{
    sceneNode->addItem(item);
}

QGraphicsScene* GraphicsSceneNode::scene() const
{
    return sceneNode.get();
}

void GraphicsSceneNode::addLeftBranch(SimpleBinaryTree *& node,
                                      const qreal endPosX2,
                                      const qreal endPosY2)
{
    const qreal beginPosX1 = 20.0;
    const qreal beginPosY1 = 40.0;
    if(node->itemLeftBranch() == nullptr)
    {
        QPointF beginPos(QPointF(node->itemNode()->pos().x() + beginPosX1,
                                 node->itemNode()->pos().y() + beginPosY1));
        QPointF endPos(QPointF(node->itemNode()->pos().x() - endPosX2,
                               node->itemNode()->pos().y() + endPosY2));
        node->setLeftBranch(new QGraphicsLineItem(QLineF(beginPos,endPos)));
        bindNodeWithBranch(node->itemNode(),node->itemLeftBranch());
        prepareCoordinateForLeftNode(node);
        sceneNode->addItem(node->itemLeftBranch());
    }
}

void GraphicsSceneNode::addRightBranch(SimpleBinaryTree *& node,
                                       const qreal endPosX2,
                                       const qreal endPosY2)
{
    const qreal beginPosX1 = 20.0;
    const qreal beginPosY1 = 40.0;

    if(node->itemRightBranch() == nullptr)
    {
        QPointF beginPos(QPointF(node->itemNode()->pos().x() + beginPosX1,
                                 node->itemNode()->pos().y() + beginPosY1));
        QPointF endPos(QPointF(node->itemNode()->pos().x() + endPosX2,
                               node->itemNode()->pos().y() + endPosY2));
        node->setRightBranch(new QGraphicsLineItem(QLineF(beginPos,endPos)));
        bindNodeWithBranch(node->itemNode(),node->itemRightBranch());
        prepareCoordinateForRightNode(node);
        sceneNode->addItem(node->itemRightBranch());
    }
}

void GraphicsSceneNode::bindBranchWithNewNode(QGraphicsLineItem *& lineItem, Node*& itemNode)
{
    if(lineItem != nullptr && itemNode != nullptr)
        lineItem->setParentItem(itemNode);
}

void GraphicsSceneNode::bindNodeWithBranch(Node*& itemNode, QGraphicsLineItem*& itemBranch)
{
    if(itemNode != nullptr && itemBranch != nullptr)
        itemNode->setParentItem(itemBranch);
}

void GraphicsSceneNode::prepareCoordinateForLeftNode(SimpleBinaryTree *&currentNode)
{
    const QPointF newCoordinate(currentNode->itemLeftBranch()->line().p2().x() - 20.0,
                             currentNode->itemLeftBranch()->line().p2().y());
    coordinate = newCoordinate;
}

void GraphicsSceneNode::prepareCoordinateForRightNode(SimpleBinaryTree *&currentNode)
{
    const QPointF newCoordinate(currentNode->itemRightBranch()->line().p2().x() - 20.0,
                             currentNode->itemRightBranch()->line().p2().y());
    coordinate = newCoordinate;
}
