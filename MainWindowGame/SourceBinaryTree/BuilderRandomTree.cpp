#include "BuilderRandomTree.h"
#include <QGraphicsLineItem>

BuilderRandomTree::BuilderRandomTree():tree(nullptr)
{

}

void BuilderRandomTree::addNodeInTree(GraphicsNode* const newNode)

{
    tree = addNodeInTree(newNode,tree);
}

SimpleBinaryTree* BuilderRandomTree::addNodeInTree(GraphicsNode* const itemNode,
                                                   SimpleBinaryTree* currentNode)
{
    if(currentNode == nullptr)
    {
        currentNode = new SimpleBinaryTree(itemNode);
        currentNode->itemNode()->setPos(graphicsTree->posNode());
        graphicsTree->addItem(currentNode->itemNode());
        return currentNode;
    }
    else if(itemNode->key() < currentNode->key())
    {
        graphicsTree->addLeftBranch(currentNode);
        graphicsTree->increaseIndex();
        currentNode->leftNode = addNodeInTree(itemNode,currentNode->leftNode);
        graphicsTree->reduceIndex();
    }
    else if(itemNode->key() > currentNode->key())
    {
        graphicsTree->addRightBranch(currentNode);
        graphicsTree->increaseIndex();
        currentNode->rightNode = addNodeInTree(itemNode,currentNode->rightNode);
        graphicsTree->reduceIndex();
    }
    return currentNode;
}

