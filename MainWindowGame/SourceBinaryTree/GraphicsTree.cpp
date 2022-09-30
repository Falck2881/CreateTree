#include "GraphicsTree.h"
#include <QTransform>

GraphicsTree::GraphicsTree():sceneNode(std::make_unique<QGraphicsScene>(QRectF(0.0,0.0,1000.0,1000.0))),
                                       index{0},position(500.0,250.0)
{
    initializeArrayOffsetBranch();
}

void GraphicsTree::initializeArrayOffsetBranch()
{
    qreal ratioAxesX2 = 1.8;
    qreal ratioAxesY2 = 4.4;
    const quint32 size{30};
    QPointF leftOffsetByAxesXY2(180.0,44.0);
    QPointF rightOffsetByAxesXY2(220.0,44.0);

    for(quint32 index = 0; index < size; ++index)
    {      
        arrayOffsetBranch.push_back(std::make_pair(leftOffsetByAxesXY2,rightOffsetByAxesXY2));
        leftOffsetByAxesXY2.setX(leftOffsetByAxesXY2.x() / ratioAxesX2);
        leftOffsetByAxesXY2.setY(leftOffsetByAxesXY2.y() + ratioAxesY2);
        rightOffsetByAxesXY2.setX(rightOffsetByAxesXY2.x() / ratioAxesX2);
        rightOffsetByAxesXY2.setY(rightOffsetByAxesXY2.y() + ratioAxesY2);
        ratioAxesX2 += 0.1;
        ratioAxesY2 += 1.2;
    }
}

QPointF GraphicsTree::posNode() const
{
    return position;
}

void GraphicsTree::addItem(QGraphicsItem *const item)
{
    sceneNode->addItem(item);
}

QGraphicsScene* GraphicsTree::scene() const
{
    return sceneNode.get();
}

void GraphicsTree::addLeftBranch(SimpleBinaryTree *& node)
{
    if(node->itemLeftBranch() == nullptr)
    {
        const QPointF leftOffsetByAxesXY2 = arrayOffsetBranch.at(index).first;

        QPointF beginPos(QPointF(node->itemNode()->pos().x() + qreal(20.0),
                                 node->itemNode()->pos().y() + qreal(40.0)));
        QPointF endPos(QPointF(node->itemNode()->pos().x() - leftOffsetByAxesXY2.x(),
                               node->itemNode()->pos().y() + leftOffsetByAxesXY2.y()));
        node->setLeftBranch(new QGraphicsLineItem(QLineF(beginPos,endPos)));
        preparePositionNewNode(node->itemLeftBranch()->line().p2());
        sceneNode->addItem(node->itemLeftBranch());
    }
}

void GraphicsTree::addRightBranch(SimpleBinaryTree *& node)
{
    if(node->itemRightBranch() == nullptr)
    {
        const QPointF rightOffsetByAxesXY2 = arrayOffsetBranch.at(index).second;

        QPointF beginPos(QPointF(node->itemNode()->pos().x() + qreal(20.0),
                                 node->itemNode()->pos().y() + qreal(40.0)));
        QPointF endPos(QPointF(node->itemNode()->pos().x() + rightOffsetByAxesXY2.x(),
                               node->itemNode()->pos().y() + rightOffsetByAxesXY2.y()));
        node->setRightBranch(new QGraphicsLineItem(QLineF(beginPos,endPos)));
        preparePositionNewNode(node->itemRightBranch()->line().p2());
        sceneNode->addItem(node->itemRightBranch());
    }
}

void GraphicsTree::preparePositionNewNode(QPointF endBranch)
{
    endBranch.setX(endBranch.x() - 20.0);
    position = endBranch;
}

void GraphicsTree::increaseIndex()
{
    ++index;
}

void GraphicsTree::reduceIndex()
{
    if(index != 0)
        --index;
}
