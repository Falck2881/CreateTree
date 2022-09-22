#include "SimpleBinaryTree.h"
#include <QPen>

SimpleBinaryTree::SimpleBinaryTree(Node* const data):
    leftNode(nullptr),rightNode(nullptr),node(data),
    leftBranch(nullptr),rightBranch(nullptr)
{}

const ushort* SimpleBinaryTree::key()
{
    return node->keyUtf16();
}

Node*& SimpleBinaryTree::itemNode()
{
    return node;
}

QGraphicsLineItem*& SimpleBinaryTree::itemLeftBranch()
{
    return leftBranch;
}

QGraphicsLineItem*& SimpleBinaryTree::itemRightBranch()
{
    return rightBranch;
}

void SimpleBinaryTree::setLeftBranch(QGraphicsLineItem* const newLeftBranch)
{
    leftBranch = newLeftBranch;
    leftBranch->setPen(QPen(Qt::black,3));
}


void SimpleBinaryTree::setRightBranch(QGraphicsLineItem *const newRightBranch)
{
    rightBranch = newRightBranch;
    rightBranch->setPen(QPen(Qt::black,3));
}
