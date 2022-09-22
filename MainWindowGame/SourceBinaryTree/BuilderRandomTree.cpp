#include "BuilderRandomTree.h"
#include <QGraphicsLineItem>

BuilderRandomTree::BuilderRandomTree():tree(nullptr)
{

}


void BuilderRandomTree::addNodeInTree(Node* const newNode)
{
    tree = addNodeInTree(newNode,tree);
}

SimpleBinaryTree* BuilderRandomTree::addNodeInTree(Node* const itemNode,
                                                   SimpleBinaryTree* currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(itemNode);
        currentNode->itemNode()->setPos(graphicsScene->coordinateNode());
        graphicsScene->addItem(currentNode->itemNode());
        return currentNode;
    }
    else if(itemNode->keyUtf16() < currentNode->key())
    {
        graphicsScene->addLeftBranch(currentNode);
        currentNode->leftNode = addNodeInTree(itemNode,currentNode->leftNode,currentNode->itemLeftBranch());
    }
    else if(itemNode->keyUtf16() > currentNode->key())
    {
        graphicsScene->addRightBranch(currentNode);
        currentNode->rightNode = addNodeInTree(itemNode,currentNode->rightNode,currentNode->itemRightBranch());
    }
    return currentNode;
}

SimpleBinaryTree* BuilderRandomTree::addNodeInTree(Node* const itemNode,
                                                   SimpleBinaryTree* currentNode,
                                                   QGraphicsLineItem*& itemBranch)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(itemNode);
        graphicsScene->bindBranchWithNewNode(itemBranch,currentNode->itemNode());
        currentNode->itemNode()->setPos(graphicsScene->coordinateNode());
        graphicsScene->addItem(currentNode->itemNode());
        return currentNode;
    }
    else if(itemNode->keyUtf16() < currentNode->key())
    {
        graphicsScene->addLeftBranch(currentNode,50.0,60.0);
        currentNode->leftNode = addNodeInTree(itemNode,currentNode->leftNode,currentNode->itemLeftBranch());
    }
    else if(itemNode->keyUtf16() > currentNode->key())
    {
        graphicsScene->addRightBranch(currentNode,80.0,60.0);
        currentNode->rightNode = addNodeInTree(itemNode,currentNode->rightNode,currentNode->itemRightBranch());
    }
    return currentNode;
}

