#include "GraphicsBinaryTree.h"
#include <QPen>

GraphicsBinaryTree::GraphicsBinaryTree(GraphicsNode* const data):
    leftNode(nullptr),rightNode(nullptr),
    _height{1},grNode(data),
    leftBranch(new QGraphicsLineItem(QLineF(0,0,0,0))),
    rightBranch(new QGraphicsLineItem(QLineF(0,0,0,0)))
{
    setPropertyBrances();
}

void GraphicsBinaryTree::setPropertyBrances()
{
    leftBranch->setPen(QPen(QBrush(Qt::black),2));
    rightBranch->setPen(QPen(QBrush(Qt::black),2));
}

GraphicsBinaryTree::GraphicsBinaryTree(GraphicsBinaryTree&& oldNode)
{
    this->leftNode = oldNode.leftNode;
    this->rightNode = oldNode.rightNode;
    this->_height = oldNode._height;
    this->grNode = oldNode.grNode;
    this->leftBranch = oldNode.leftBranch;
    this->rightBranch = oldNode.rightBranch;

    oldNode.leftNode = nullptr;
    oldNode.rightNode = nullptr;
    oldNode._height = 0;
    oldNode.grNode = nullptr;
    oldNode.leftBranch = nullptr;
    oldNode.rightBranch = nullptr;
}



GraphicsBinaryTree& GraphicsBinaryTree::operator=(GraphicsBinaryTree &&oldNode)
{
    if(this == &oldNode)
        return *this;

    this->leftNode = oldNode.leftNode;
    this->rightNode = oldNode.rightNode;
    this->_height = oldNode._height;
    this->grNode = oldNode.grNode;
    this->leftBranch = oldNode.leftBranch;
    this->rightBranch = oldNode.rightBranch;

    oldNode.leftNode = nullptr;
    oldNode.rightNode = nullptr;
    oldNode._height = 0;
    oldNode.grNode = nullptr;
    oldNode.leftBranch = nullptr;
    oldNode.rightBranch = nullptr;

    return *this;
}

uint GraphicsBinaryTree::key()
{
    return grNode->key();
}

GraphicsNode* GraphicsBinaryTree::itemNode() const
{
    return grNode;
}

QGraphicsLineItem* GraphicsBinaryTree::itemLeftBranch() const
{
    return leftBranch;
}

QGraphicsLineItem* GraphicsBinaryTree::itemRightBranch() const
{
    return rightBranch;
}

qint32 GraphicsBinaryTree::height() const
{
    return _height;
}

QPointF GraphicsBinaryTree::p2LeftBranch() const
{
    const QPointF pos(leftBranch->line().p2().x()-20.0,leftBranch->line().p2().y());
    return pos;
}

QPointF GraphicsBinaryTree::p2RightBranch() const
{
    const QPointF pos(rightBranch->line().p2().x()-20.0,rightBranch->line().p2().y());
    return pos;
}

qreal GraphicsBinaryTree::posBottomX() const
{
    return grNode->pos().x()+20.0;
}

qreal GraphicsBinaryTree::posBottomY() const
{
    return grNode->pos().y()+40.0;
}

void GraphicsBinaryTree::setPosLeftBranch(const QLineF line)
{
    leftBranch->setLine(line);
}

void GraphicsBinaryTree::setPosRightBranch(const QLineF line)
{
    rightBranch->setLine(line);
}

void GraphicsBinaryTree::setHeight(const qint32 newHeight)
{
    _height=newHeight;
}

void GraphicsBinaryTree::setPosItems(const QPointF startPos)
{
    grNode->updatePos(startPos);
}

void GraphicsBinaryTree::update()
{
    tree.updatePositionTree(this);
}

GraphicsBinaryTree::~GraphicsBinaryTree()
{
    delete grNode;
    delete leftBranch;
    delete rightBranch;
    delete leftNode;
    delete rightNode;
}
