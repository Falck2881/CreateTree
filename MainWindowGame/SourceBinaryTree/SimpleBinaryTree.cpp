#include "SimpleBinaryTree.h"
#include <QPen>

SimpleBinaryTree::SimpleBinaryTree(GraphicsNode* const data):
    leftNode(nullptr),rightNode(nullptr),
    _height{1},node(data),leftBranch(nullptr),rightBranch(nullptr)
{
}

SimpleBinaryTree::SimpleBinaryTree(SimpleBinaryTree&& oldNode)
{
    this->leftNode = oldNode.leftNode;
    this->rightNode = oldNode.rightNode;
    this->_height = oldNode._height;
    this->node = oldNode.node;
    this->leftBranch = oldNode.leftBranch;
    this->rightBranch = oldNode.rightBranch;

    oldNode.leftNode = nullptr;
    oldNode.rightNode = nullptr;
    oldNode._height = 0;
    oldNode.node = nullptr;
    oldNode.leftBranch = nullptr;
    oldNode.rightBranch = nullptr;
}

SimpleBinaryTree& SimpleBinaryTree::operator=(SimpleBinaryTree &&oldNode)
{
    if(this == &oldNode)
        return *this;

    this->leftNode = oldNode.leftNode;
    this->rightNode = oldNode.rightNode;
    this->_height = oldNode._height;
    this->node = oldNode.node;
    this->leftBranch = oldNode.leftBranch;
    this->rightBranch = oldNode.rightBranch;

    oldNode.leftNode = nullptr;
    oldNode.rightNode = nullptr;
    oldNode._height = 0;
    oldNode.node = nullptr;
    oldNode.leftBranch = nullptr;
    oldNode.rightBranch = nullptr;

    return *this;
}

uint SimpleBinaryTree::key()
{
    return node->key();
}

GraphicsNode*& SimpleBinaryTree::itemNode()
{
    return node;
}

void SimpleBinaryTree::setPositionGraphicsItems(const QPointF posNode, std::pair<QPointF, QPointF> offsetBranchesByAxesXY2)
{
    node->setPos(QPointF(posNode.x() - 20.0,posNode.y()));

    if(node->pos() != QPointF(0.0,0.0))
        createBranches(offsetBranchesByAxesXY2);
}

void SimpleBinaryTree::createBranches(std::pair<QPointF, QPointF> offsetBranchesByAxesXY2)
{
    const QPointF beginXY1(node->pos().x() + qreal(20.0),
                           node->pos().y() + qreal(40.0));

    const QPointF leftEndPosXY2(node->pos().x() - offsetBranchesByAxesXY2.first.x(),
                                node->pos().y() + offsetBranchesByAxesXY2.first.y());

    const QPointF rightEndPosXY2(node->pos().x() + offsetBranchesByAxesXY2.second.x(),
                                 node->pos().y() + offsetBranchesByAxesXY2.second.y());

    leftBranch = new QGraphicsLineItem(QLineF(beginXY1, leftEndPosXY2));
    leftBranch->setPen(QPen(Qt::black,3));
    leftBranch->hide();

    rightBranch = new QGraphicsLineItem(QLineF(beginXY1, rightEndPosXY2));
    rightBranch->setPen(QPen(Qt::black,3));
    rightBranch->hide();
}

QGraphicsLineItem*& SimpleBinaryTree::itemLeftBranch()
{
    return leftBranch;
}

QGraphicsLineItem*& SimpleBinaryTree::itemRightBranch()
{
    return rightBranch;
}

qint32 SimpleBinaryTree::height() const
{
    return _height;
}

void SimpleBinaryTree::setHeight(const qint32 newHeight)
{
    _height=newHeight;
}

SimpleBinaryTree::~SimpleBinaryTree()
{
    delete node;
    delete leftBranch;
    delete rightBranch;
    delete leftNode;
    delete rightNode;
}
